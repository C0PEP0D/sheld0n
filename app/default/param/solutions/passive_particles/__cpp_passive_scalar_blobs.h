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
	inline static const double InitC = 0.5;
	inline static const double InitS = std::pow(2, -3);
	inline static const double Dx = std::pow(2, -3);
	inline static const double Cth = std::pow(2, -16);
	// ---------------- CUSTOM EQUATION PARAMETERS END

	using Bin = sp0ce::Bin<DIM>;
	inline static Bin bin = Bin(Dx);

	// variable

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;
			// ---------------- CUSTOM CONSTRAIN START
			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);
			Flow::prepareVelocityGradients(cX.data(), t);
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

			// source
			{
				const tSpaceVector sourceX = tSpaceVector::Zero();
				const double sourceC = tGroupVariable::c(_state.data(), _state.size(), sourceX.data());
				const double sourceTargetC = InitC;

				if(sourceTargetC > sourceC) {
					tBase::pushBackMember(_state);
					
					double* pNewState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);

					tView<tSpaceVector> newX(pNewState);
					tView<tSpaceMatrix> newS(pNewState + DIM);
					double& newQ = pNewState[DIM + DIM * DIM];

					newX = sourceX;
					newS = tSpaceMatrix::Identity() * InitS;
					newQ = (sourceTargetC - sourceC) * (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(std::pow(InitS, DIM)));
				}
			}
			
			// duplicate stretched points
			
			for(int index = 0; index < tBase::groupSize(_state.size()); ++index) {
				double* pMemberState = tBase::state(_state.data(), index);
				
				tView<tSpaceVector> memberX(pMemberState);
				tView<tSpaceMatrix> memberS(pMemberState + DIM);
				double& memberQ = pMemberState[DIM + DIM * DIM];

				const double memberC = memberQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(memberS.determinant()));

// 				// // // option 1: compute direct
// 				Eigen::EigenSolver<tSpaceMatrix> solver(memberS);
// 				auto eigenValues = solver.eigenvalues().real();
// 				const auto eigenVectors = solver.eigenvectors().real();
// 
// 				auto itMaxEigenValue = std::max_element(eigenValues.begin(), eigenValues.end());
// 
// 				const double maxVariance = *itMaxEigenValue;
// 				const double maxStandardDeviation = std::sqrt(maxVariance);
// 				const unsigned int maxIndex = std::distance(eigenValues.begin(), itMaxEigenValue);
// 				const tSpaceVector maxVarianceDirection = eigenVectors.col(maxIndex);
				
				// // // option 2: compute by deformation matrix
				Eigen::SelfAdjointEigenSolver<tSpaceMatrix> solver(memberS.transpose() * memberS);
				const tSpaceVector eigenValues = solver.eigenvalues();
				const tSpaceMatrix eigenVectors = solver.eigenvectors();

				auto itMaxEigenValue = std::max_element(eigenValues.begin(), eigenValues.end());

				const double maxVariance = std::sqrt(*itMaxEigenValue);
				const double maxStandardDeviation = std::sqrt(maxVariance);
				const unsigned int maxIndex = std::distance(eigenValues.begin(), itMaxEigenValue);
				const tSpaceVector maxVarianceDirection = eigenVectors.col(maxIndex);

				const double distance = Dx;

				if(memberC > Cth) {
					if(maxStandardDeviation > 3.0 * distance) {

						const tSpaceVector splitX = memberX;
						const tSpaceMatrix splitS = memberS - 0.25 * std::pow(distance, 2) * maxVarianceDirection * maxVarianceDirection.transpose();
						const double splitQ = 0.5 * memberQ;

						// edit member

						memberX = splitX - 0.5 * distance * maxVarianceDirection;
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
	
						newX = splitX + 0.5 * distance * maxVarianceDirection;
						newS = splitS;
						newQ = splitQ;
					}
				} else {
					// std::cout << "INFO: Member erased below concentration threshold" << std::endl;
					tBase::eraseMember(_state, index);
					index -= 1;
				}
			}

			// refill bin

			updateBin(_state.data(), _state.size());

			std::vector<double> newState;
			for (auto const& [ijk, indexes] : bin.ijkToIndexes) {

				tBase::pushBackMember(newState);

				double* pNewState = tBase::state(newState.data(), tBase::groupSize(newState.size()) - 1);

				tView<tSpaceVector> newX(pNewState);
				tView<tSpaceMatrix> newS(pNewState + DIM);
				double& newQ = pNewState[DIM + DIM * DIM];

				newX = tSpaceVector::Zero();
				newQ = 0.0;
				for (auto const& index : indexes) {
					const double* pMemberState = tBase::cState(_state.data(), index);
									
					const tView<const tSpaceVector> memberX(pMemberState);
					const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
					const double memberQ = pMemberState[DIM + DIM * DIM];
	
					newX += memberQ * memberX;
					newQ += memberQ;
				}
				newX /= newQ;

				newS = tSpaceMatrix::Zero();
				for (auto const& index : indexes) {
					const double* pMemberState = tBase::cState(_state.data(), index);
									
					const tView<const tSpaceVector> memberX(pMemberState);
					const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
					const double memberQ = pMemberState[DIM + DIM * DIM];

					const tSpaceVector r = memberX - newX;
					newS += memberQ * (memberS + r * r.transpose());
				}
				newS /= newQ;
			}

			_state = newState;

			// ---------------- CUSTOM CONSTRAIN END
			
		}

		static void updateBin(const double* pState, const unsigned int stateSize) {
			bin.clear();
			for(unsigned int index = 0; index < tBase::groupSize(stateSize); ++index) {
				const double* pMemberState = tBase::cState(pState, index);
				const tView<const tSpaceVector> x(pMemberState);

				bin.addIndex(index, x.data());
			}
		}

		static double c(const double* pState, const unsigned int stateSize, const double* pX) {
			// input
			const tView<const tSpaceVector> x(pX);
			// get indexs
			const std::array<int, DIM> ijk = bin.positionToIjk(x.data());
			const std::vector<std::array<int, DIM>> neighborIjk = bin.ijkToNeighborIjk(ijk.data());
			// compute
			double output = 0.0;
			for(const std::array<int, DIM>& _ijk : neighborIjk) {
				auto itIjkToIndexes = bin.ijkToIndexes.find(_ijk);
				if(itIjkToIndexes != bin.ijkToIndexes.end()) {
					for(unsigned int& index : bin.ijkToIndexes[_ijk]) {
						// input
						const double* pMemberState = tBase::cState(pState, index);
						const tView<const tSpaceVector> memberX(pMemberState);
						const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
						const double memberQ = pMemberState[DIM + DIM * DIM];

						const double memberC = memberQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(memberS.determinant()));
						
						// compute
						const tSpaceVector r = x - memberX;
						// concentration
						output += memberC * std::exp(-0.5 * r.transpose() * memberS * r);
					}
				}
			}
			return output;
		}

		static tSpaceVector cGradient(const double* pState, const unsigned int stateSize, const double* pX) {
			// input
			const tView<const tSpaceVector> x(pX);
			// get indexs
			const std::array<int, DIM> ijk = bin.positionToIjk(x.data());
			const std::vector<std::array<int, DIM>> neighborIjk = bin.ijkToNeighborIjk(ijk.data());
			// compute
			tSpaceVector output = tSpaceVector::Zero();
			for(const std::array<int, DIM>& _ijk : neighborIjk) {
				auto itIjkToIndexes = bin.ijkToIndexes.find(_ijk);
				if(itIjkToIndexes != bin.ijkToIndexes.end()) {
					for(unsigned int& index : bin.ijkToIndexes[_ijk]) {
						// input
						const double* pMemberState = tBase::cState(pState, index);
						const tView<const tSpaceVector> memberX(pMemberState);
						const tView<const tSpaceMatrix> memberS(pMemberState + DIM);
						const double memberQ = pMemberState[DIM + DIM * DIM];

						const double memberC = memberQ / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(memberS.determinant()));
						
						// compute
						const tSpaceVector r = x - memberX;
						// concentration
						output += -0.5 * memberC * std::exp(-0.5 * r.transpose() * memberS * r) * memberS * r;
					}
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
			const tSpaceVector uD = ( Diffusivity / tGroupVariable::c(pGroupState, groupStateSize, x.data()) ) * tGroupVariable::cGradient(pGroupState, groupStateSize, x.data());
			// // output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceMatrix> dS(dState.data() + DIM);
			double& dQ = dState[DIM + DIM * DIM];

			// // // option 1: equation isotropic
			// dX = u + uD;
			// dS = 2.0 * Diffusivity * tSpaceMatrix::Identity();
			// dQ = 0.0;

			// // option 2: equation anisotropic
			dX = u + uD;
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
			
			tGroupVariable::updateBin(pState, stateSize);

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
		tGroupVariable::updateBin(pState, stateSize);

		{ // particles
			unsigned int number = tVariable::groupSize(stateSize);
			unsigned int formatNumber = int(std::log10(number)) + 1;
			
			tSpaceVector xAverage = tSpaceVector::Zero();
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
				// compute average
				xAverage += x;
			}
			xAverage /= number;
			output["passive_particles__average_pos_0"] = xAverage[0];
			output["passive_particles__average_pos_1"] = xAverage[1];
		}

		{ // profile
			unsigned int number = std::round(4.0 * M_PI/Dx);
			unsigned int formatNumber = int(std::log10(number)) + 1;
			
			for(unsigned int index = 0; index < number; ++index) {
				const tSpaceVector x({(-0.5 * number + index) * Dx, 0.0});
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
