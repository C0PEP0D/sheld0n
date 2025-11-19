#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// lib includes
#include "sp0ce/bin.h" // bin

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"

#include "param/parameters.h"
#include "param/run/parameters.h"

// FLAG: DYNAMIC

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM + DIM * DIM + 1; // x, s, q
	// feel free to add parameters if you need
	inline static const double Diffusivity = std::pow(2, -6);
	inline static const tSpaceVector InitX = tSpaceVector({0.0, 0.0});
	inline static const double InitC = 1.0;
	inline static const double InitS = std::pow(2, -3);

	// splitting
	static const bool IsSplitting = true;
	inline static const double Dx = std::pow(2, -1);
	inline static const double SplitSize = Dx;
	inline static const double OverlapFactor = 4.0; // must be bigger than 2, increase to increase accuracy at the cost of computation time
	inline static const double SplitDistance = SplitSize / OverlapFactor;
	inline static const double MergeDx = SplitDistance / std::sqrt(DIM);
	static const bool IsApproximatingWhithBin = true;
	// concentration threshold (for blob deletion)
	inline static const double Cth = std::pow(2, -32);
	inline static const double Qth = Cth * std::pow(Dx, DIM);

	// source
	static const bool HasSource = true;
	inline static const tSpaceVector SourceX = InitX;
	inline static const double SourceC = InitC;
	inline static const double SourceS = InitS;
	inline static const double SourceReactionTime = 1.0;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	// concentration threshold
	inline static bool hasBlobBeenDeleted = false;

	// bin
	
	using BinTree = sp0ce::BinTree<DIM>;
	inline static BinTree binTree = BinTree(MergeDx);
	// super
	inline static std::vector<std::map<std::array<int, DIM>, unsigned int>> ijkToSuperIndex;
	inline static std::vector<std::vector<double>> superStateArray;

	// variable

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;

			// ---------------- CUSTOM CONSTRAIN START

			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	struct tGroupVariable : public d0t::VariableGroupDynamic<tMemberVariable> {
		using tBase = d0t::VariableGroupDynamic<tMemberVariable>;

		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int stateIndex) {
			tBase::_constrain(stateArray, t, stateIndex);
			// input
			std::vector<double>& _state = stateArray[stateIndex];

			// ---------------- CUSTOM CONSTRAIN START
			if (IsSplitting) {
				// source
				if (HasSource) {
					const double c = tGroupVariable::c(_state.data(), _state.size(), SourceX.data());

					if(c < SourceC) {
						tBase::pushBackMember(_state);
						
						double* pNewState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);

						tView<tSpaceVector> newX(pNewState);
						tView<tSpaceMatrix> newS(pNewState + DIM);
						double& newQ = pNewState[DIM + DIM * DIM];

						newX = SourceX;
						newS = tSpaceMatrix::Identity() * SourceS;
						newQ = (SourceC - c) * std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(std::pow(SourceS, DIM)) / SourceReactionTime;
					}
				}
				
				// split
				
				for(int index = 0; index < tBase::groupSize(_state.size()); ++index) {
					double* pMemberState = tBase::state(_state.data(), index);
					
					tView<tSpaceVector> memberX(pMemberState);
					tView<tSpaceMatrix> memberS(pMemberState + DIM);
					double& memberQ = pMemberState[DIM + DIM * DIM];

					if(memberQ > Qth) {
						Eigen::SelfAdjointEigenSolver<tSpaceMatrix> solver(memberS.transpose() * memberS);
						const tSpaceVector eigenValues = solver.eigenvalues();
						const tSpaceMatrix eigenVectors = solver.eigenvectors();
	
						auto itMaxEigenValue = std::max_element(eigenValues.begin(), eigenValues.end());
	
						const double maxVariance = std::sqrt(*itMaxEigenValue);
						const double maxStandardDeviation = std::sqrt(maxVariance);
						const unsigned int maxIndex = std::distance(eigenValues.begin(), itMaxEigenValue);
						const tSpaceVector maxVarianceDirection = eigenVectors.col(maxIndex);
					
						if(maxStandardDeviation > SplitSize) {

							const tSpaceVector splitX = memberX;
							const tSpaceMatrix splitS = memberS - 0.25 * std::pow(SplitDistance, 2) * maxVarianceDirection * maxVarianceDirection.transpose();
							const double splitQ = 0.5 * memberQ;

							// edit member

							memberX = splitX - 0.5 * SplitDistance * maxVarianceDirection;
							memberS = splitS;
							memberQ = splitQ;
		
							// add new member
		
							tBase::pushBackMember(_state);
							// set initial state
							double* pNewState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);
							// x
							tView<tSpaceVector> newX(pNewState);
							tView<tSpaceMatrix> newS(pNewState + DIM);
							double& newQ = pNewState[DIM + DIM * DIM];
		
							newX = splitX + 0.5 * SplitDistance * maxVarianceDirection;
							newS = splitS;
							newQ = splitQ;
						}
					} else {
						tBase::eraseMember(_state, index);
						index -= 1;
						if(not hasBlobBeenDeleted) {
							std::cout << "INFO : A scalar blob has fallen below the concentration threshold and has been deleted. This message will not bee displayed again." << std::endl;
							hasBlobBeenDeleted = true;
						}
					}
				}

				// merge

				prepareSuper(_state.data(), _state.size());
				_state = superStateArray[0];
			}
			// ---------------- CUSTOM CONSTRAIN END
			
		}

		static void prepareSuper(const double* pState, const unsigned int stateSize) {
			// fill tree
			binTree.clear();
			for(unsigned int index = 0; index < tBase::groupSize(stateSize); ++index) {
				const double* pMemberState = tBase::cState(pState, index);
				const tView<const tSpaceVector> x(pMemberState);

				binTree.addIndex(index, x.data());
			}

			// compute super blobs
			ijkToSuperIndex.clear();
			superStateArray.clear();
			// 0
			ijkToSuperIndex.emplace_back();
			superStateArray.emplace_back();
			for (auto const& [ijk, indexes] : binTree.data[0].ijkToIndexes) {
				// init
				ijkToSuperIndex[0][ijk] = ijkToSuperIndex[0].size();
				superStateArray[0].resize(ijkToSuperIndex[0].size() * StateSize, 0.0);
				// output
				tView<tSpaceVector> superX(&(superStateArray[0][superStateArray[0].size() - StateSize]));
				tView<tSpaceMatrix> superS(&(superStateArray[0][superStateArray[0].size() - StateSize + DIM]));
				double& superQ = superStateArray[0][superStateArray[0].size() - StateSize + DIM + DIM * DIM];
				// x
				for (auto const& index : indexes) {

					const double* pMemberState = tBase::cState(pState, index);

					const tView<const tSpaceVector> memberX(pMemberState);
					const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
					const double memberQ = pMemberState[DIM + DIM * DIM];

					superX += memberQ * memberX;
					superQ += memberQ;
				}
				superX /= superQ;
				// s
				for (auto const& index : indexes) {
					const double* pMemberState = tBase::cState(pState, index);
									
					const tView<const tSpaceVector> memberX(pMemberState);
					const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
					const double memberQ = pMemberState[DIM + DIM * DIM];

					const tSpaceVector r = memberX - superX;
					superS += memberQ * (memberS + r * r.transpose());
				}
				superS /= superQ;
			}
			// others
			for(unsigned int i = 1; i < binTree.data.size(); ++i) {
				ijkToSuperIndex.emplace_back();
				superStateArray.emplace_back();
				for (auto const& [ijk, indexes] : binTree.data[i].ijkToIndexes) {
					// init
					ijkToSuperIndex[i][ijk] = ijkToSuperIndex[i].size();
					superStateArray[i].resize(ijkToSuperIndex[i].size() * StateSize, 0.0);
					
					// process
					tView<tSpaceVector> superX(&(superStateArray[i][superStateArray[i].size() - StateSize]));
					tView<tSpaceMatrix> superS(&(superStateArray[i][superStateArray[i].size() - StateSize + DIM]));
					double& superQ = superStateArray[i][superStateArray[i].size() - StateSize + DIM + DIM * DIM];
					// sub
					std::array<int, DIM> subIjkStart;
					std::array<int, DIM> subIjkEnd;
					for(unsigned int j = 0; j < DIM; ++j) {
						subIjkStart[j] = ijk[j] * 2;
						subIjkEnd[j] = (ijk[j] + 1) * 2;
					}
					// x
					for (auto const& subIjk : binTree.data[i-1].getIjkInBetween(subIjkStart.data(), subIjkEnd.data())) {
						auto iterator = ijkToSuperIndex[i-1].find(subIjk);
						if(iterator != ijkToSuperIndex[i-1].end()) {
							const unsigned int subIndex = iterator->second;

							const tView<const tSpaceVector> subX(&(superStateArray[i-1][subIndex * StateSize]));
							const tView<const tSpaceMatrix> subS(&(superStateArray[i-1][subIndex * StateSize + DIM]));
							const double subQ = superStateArray[i-1][subIndex * StateSize + DIM + DIM * DIM];

							superX += subQ * subX;
							superQ += subQ;
						}
					}
					superX /= superQ;
					// s
					for (auto const& subIjk : binTree.data[i-1].getIjkInBetween(subIjkStart.data(), subIjkEnd.data())) {
						auto iterator = ijkToSuperIndex[i-1].find(subIjk);
						if(iterator != ijkToSuperIndex[i-1].end()) {
							const unsigned int subIndex = iterator->second;

							const tView<const tSpaceVector> subX(&(superStateArray[i-1][subIndex * StateSize]));
							const tView<const tSpaceMatrix> subS(&(superStateArray[i-1][subIndex * StateSize + DIM]));
							const double subQ = superStateArray[i-1][subIndex * StateSize + DIM + DIM * DIM];

							const tSpaceVector r = subX - superX;
							superS += subQ * (subS + r * r.transpose());
						}
					}
					superS /= superQ;
				}
			}
		}

		static double c(const double* pState, const unsigned int stateSize, const double* pX) {
			// input
			const tView<const tSpaceVector> x(pX);
			// output
			double output = 0.0;
			// compute
			if (IsSplitting && IsApproximatingWhithBin) {
				std::vector<std::array<int, DIM>> childrenIjkArray;
				for (auto [key, value] : binTree.data[binTree.data.size() - 1].ijkToIndexes) {
				    childrenIjkArray.push_back(key);
				}

				for(unsigned int i = binTree.data.size() - 1; i > 0; --i) {
					const std::array<int, DIM> ijk = binTree.data[i].positionToIjk(x.data());
					const std::vector<std::array<int, DIM>> neighborIjkArray = binTree.data[i].ijkToNeighborIjk( ijk.data() );
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						if(std::find(neighborIjkArray.begin(), neighborIjkArray.end(), childIjk) == neighborIjkArray.end()) {
							auto iterator = ijkToSuperIndex[i].find(childIjk);
							if(iterator != ijkToSuperIndex[i].end()) {
								const unsigned int superIndex = iterator->second;
								const double* pSuperState = superStateArray[i].data() + superIndex * StateSize;
								const tView<const tSpaceVector> superX(pSuperState);
								const tView<const tSpaceMatrix> superS(pSuperState + DIM);
								const double superQ = pSuperState[DIM + DIM * DIM];
								
								const double superC = superQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(superS.determinant()));
								
								// compute
								const tSpaceVector r = x - superX;
								// concentration
								output += superC * std::exp(-0.5 * r.transpose() * superS.inverse() * r);
							}
						}
					}
					// next
					childrenIjkArray.clear();
					for(const std::array<int, DIM>& neighborIjk : neighborIjkArray) {
						const std::vector<std::array<int, DIM>>& neighborChildren = binTree.data[i].ijkToChildrenIjk(neighborIjk.data());
						childrenIjkArray.insert(childrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
					}
				}

				{ // i == 0
					const std::array<int, DIM> ijk = binTree.data[0].positionToIjk(x.data());
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[0].find(childIjk);
						if(iterator != ijkToSuperIndex[0].end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = superStateArray[0].data() + superIndex * StateSize;
							const tView<const tSpaceVector> superX(pSuperState);
							const tView<const tSpaceMatrix> superS(pSuperState + DIM);
							const double superQ = pSuperState[DIM + DIM * DIM];
							
							const double superC = superQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(superS.determinant()));
							
							// compute
							const tSpaceVector r = x - superX;
							// concentration
							output += superC * std::exp(-0.5 * r.transpose() * superS.inverse() * r);
						}
					}
				}
			} else {
				for(unsigned int index = 0; index < tGroupVariable::groupSize(stateSize); ++index) {
					// input
					const double* pMemberState = tBase::cState(pState, index);
					const tView<const tSpaceVector> memberX(pMemberState);
					const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
					const double memberQ = pMemberState[DIM + DIM * DIM];

					const double memberC = memberQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(memberS.determinant()));
					
					// compute
					const tSpaceVector r = x - memberX;
					// concentration
					output += memberC * std::exp(-0.5 * r.transpose() * memberS.inverse() * r);
				}
			}
			return output;
		}

		static tSpaceVector cGradient(const double* pState, const unsigned int stateSize, const double* pX) {
			// input
			const tView<const tSpaceVector> x(pX);
			// output
			tSpaceVector output = tSpaceVector::Zero();
			//compute
			if (IsSplitting && IsApproximatingWhithBin) {
				std::vector<std::array<int, DIM>> childrenIjkArray;
				for (auto [key, value] : binTree.data[binTree.data.size() - 1].ijkToIndexes) {
				    childrenIjkArray.push_back(key);
				}

				for(unsigned int i = binTree.data.size() - 1; i > 0; --i) {
					const std::array<int, DIM> ijk = binTree.data[i].positionToIjk(x.data());
					const std::vector<std::array<int, DIM>> neighborIjkArray = binTree.data[i].ijkToNeighborIjk( ijk.data() );
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						if(std::find(neighborIjkArray.begin(), neighborIjkArray.end(), childIjk) == neighborIjkArray.end()) {
							auto iterator = ijkToSuperIndex[i].find(childIjk);
							if(iterator != ijkToSuperIndex[i].end()) {
								const unsigned int superIndex = iterator->second;
								const double* pSuperState = superStateArray[i].data() + superIndex * StateSize;
								const tView<const tSpaceVector> superX(pSuperState);
								const tView<const tSpaceMatrix> superS(pSuperState + DIM);
								const double superQ = pSuperState[DIM + DIM * DIM];
								
								const double superC = superQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(superS.determinant()));
								const tSpaceMatrix superSInverse = superS.inverse();
								
								// compute
								const tSpaceVector r = x - superX;
								// concentration
								output += -superC * superSInverse * r * std::exp(-0.5 * r.transpose() * superSInverse * r);
							}
						}
					}
					// next
					childrenIjkArray.clear();
					for(const std::array<int, DIM>& neighborIjk : neighborIjkArray) {
						const std::vector<std::array<int, DIM>>& neighborChildren = binTree.data[i].ijkToChildrenIjk(neighborIjk.data());
						childrenIjkArray.insert(childrenIjkArray.end(), neighborChildren.begin(), neighborChildren.end());
					}
				}

				{ // i == 0
					const std::array<int, DIM> ijk = binTree.data[0].positionToIjk(x.data());
					
					// compute
					for(auto const& childIjk : childrenIjkArray) {
						auto iterator = ijkToSuperIndex[0].find(childIjk);
						if(iterator != ijkToSuperIndex[0].end()) {
							const unsigned int superIndex = iterator->second;
							const double* pSuperState = superStateArray[0].data() + superIndex * StateSize;
							const tView<const tSpaceVector> superX(pSuperState);
							const tView<const tSpaceMatrix> superS(pSuperState + DIM);
							const double superQ = pSuperState[DIM + DIM * DIM];
							
							const double superC = superQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(superS.determinant()));
							const tSpaceMatrix superSInverse = superS.inverse();
															
							// compute
							const tSpaceVector r = x - superX;
							// concentration
							output += -superC * superSInverse * r * std::exp(-0.5 * r.transpose() * superSInverse * r);
						}
					}
				}
			} else {
				for(unsigned int index = 0; index < tGroupVariable::groupSize(stateSize); ++index) {
					// input
					const double* pMemberState = tBase::cState(pState, index);
					const tView<const tSpaceVector> memberX(pMemberState);
					const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
					const double memberQ = pMemberState[DIM + DIM * DIM];

					const double memberC = memberQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(memberS.determinant()));
					const tSpaceMatrix memberSInverse = memberS.inverse();
					
					// compute
					const tSpaceVector r = x - memberX;
					// concentration
					output += -memberC * memberSInverse * r * std::exp(-0.5 * r.transpose() * memberSInverse * r);
				}
			}
			return output;
		}
	};
	using tVariable = tGroupVariable;

	// equation

	struct tMemberEquation : public d0t::Equation<tMemberVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// ---------------- CUSTOM PREPARATION START
			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);
			Flow::prepareVelocityGradients(cX.data(), t);
			// ---------------- CUSTOM PREPARATION END
		}
	
		static tStateVectorDynamic stateTemporalDerivative(const double* const * pStateArray, const unsigned int* pStateSize, const unsigned int arraySize, const double t, const unsigned int memberIndex) {
			// static input
			const unsigned int groupStateSize = pStateSize[StateIndex];
			const double* pGroupState = pStateArray[StateIndex];
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[StateIndex], memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// advection
			// // input
			const tView<const tSpaceVector> x(pState);
			const tView<const tSpaceMatrix> s(pState + DIM);
			const tView<const tSpaceMatrix> q(pState + DIM + DIM * DIM);
			// // flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			const tSpaceMatrix j = Flow::getVelocityGradients(x.data(), t);
			// // utils
			// const tSpaceVector uD = ( Diffusivity / tGroupVariable::c(pGroupState, groupStateSize, x.data()) ) * tGroupVariable::cGradient(pGroupState, groupStateSize, x.data());
			// // output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceMatrix> dS(dState.data() + DIM);
			double& dQ = dState[DIM + DIM * DIM];

			dX = u; // u + uD ? ;
			dS = 2.0 * Diffusivity * tSpaceMatrix::Identity() + j * s + s * j.transpose();
			dQ = 0.0;

			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}

	};
	struct tGroupEquation : public d0t::EquationGroupDynamic<tVariable, tMemberEquation> {
		using tBase = d0t::EquationGroupDynamic<tVariable, tMemberEquation>;
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			tBase::prepare(pState, stateSize, t);

			// ---------------- CUSTOM PREPARATION START
			
			tGroupVariable::prepareSuper(pState, stateSize);

			// ---------------- CUSTOM PREPARATION END
		}
	};
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(std::vector<double>& state) {
		// ---------------- CUSTOM INIT START

		{ // 0
			tGroupVariable::pushBackMember(state);
			// set initial state
			double* pState = tGroupVariable::state(state.data(), tGroupVariable::groupSize(state.size()) - 1);
			// define
			tView<tSpaceVector> x(pState);
			tView<tSpaceMatrix> s(pState + DIM);
			double& q = pState[DIM + DIM * DIM];
			// set
			x = tSpaceVector::Zero();
			// x = tSpaceVector({1.0, 0.0});
			s = tSpaceMatrix::Identity() * InitS;
			q = InitC * (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(std::pow(InitS, DIM)));
		}
		
		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		tGroupVariable::prepareSuper(pState, stateSize);

		{ // particles
			unsigned int number = tVariable::groupSize(stateSize);
			unsigned int formatNumber = int(std::log10(number)) + 1;
			
			for(unsigned int index = 0; index < number; ++index) {
				const double* pMemberState = tVariable::cState(pState, index);
				// input
				const tView<const tSpaceVector> x(pMemberState);
				// generate formated index
				std::ostringstream ossIndex;
				ossIndex << "passive_particles__index_" << std::setw(formatNumber) << std::setfill('0') << index;
				// output
				output[ossIndex.str() + "__pos_0"] = x[0];
				output[ossIndex.str() + "__pos_1"] = x[1];
				output[ossIndex.str() + "__c"] = tGroupVariable::c(pState, stateSize, x.data());
			}
		}

		{ // profile
			unsigned int number = std::round(4.0 * M_PI/MergeDx);
			unsigned int formatNumber = int(std::log10(number)) + 1;
			
			for(unsigned int index = 0; index < number; ++index) {
				const tSpaceVector x({(-0.5 * number + index) * MergeDx, 0.0});
				// generate formated index
				std::ostringstream ossIndex;
				ossIndex << "profile_c__index_" << std::setw(formatNumber) << std::setfill('0') << index;
				// output
				output[ossIndex.str() + "__x"] = x[0];
				output[ossIndex.str() + "__c"] = tGroupVariable::c(pState, stateSize, x.data());
			}
		}
		
		// ---------------- CUSTOM INIT END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
