#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// lib includes
#include "pl0f/scalar_field.h"

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
	static const unsigned int StateSize = DIM + DIM * DIM + 1; // x, s, q
	// feel free to add parameters if you need
	inline static const double Diffusivity = 1.0e-2;

	// init
	static const bool HasInit = false;
	inline static const tSpaceVector InitX = tSpaceVector::Zero();
	inline static const double InitC = 1.0;
	inline static const tSpaceMatrix InitS = tSpaceVector({1.0e-1, 1.0e-1}).asDiagonal();

	// splitting
	static const bool IsSplitting = true;
	
	inline static const double SplitSizeFactor = 1e-1; // decrease to increase accuracy at the cost of computation time
	inline static const double SplitDistanceFactor = 2.0/5.0; // must be bigger smaller than 1/2 to avoid concentration increase when splitting, decrease for accuracy at the cost of computation time

	inline static const double SplitSize = SplitSizeFactor * EnvParameters::cLength;
	inline static const double SplitDistance = SplitDistanceFactor * SplitSize;
	inline static const double MergeDx = SplitDistance / std::sqrt(DIM);
	// concentration threshold (for blob deletion)
	inline static const double Cth = 1.0e-6;
	inline static const double Qth = Cth * std::pow(MergeDx, DIM);

	// source
	static const bool HasSource = false;
	inline static const tSpaceVector SourceX = InitX;
	inline static const double SourceC = InitC;
	inline static const tSpaceMatrix SourceS = InitS;
	inline static const double SourceReactionTime = 1.0;

	// periodicity
	inline static const tSpaceVector periodCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector periodSize = EnvParameters::cDomainSize;
	inline static const std::array<bool, DIM> isAxisPeriodic = EnvParameters::cDomainIsAxisPeriodic;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	// concentration threshold
	inline static bool hasBlobBeenDeleted = false;

	// scalar field
	using ScalarField = pl0f::ScalarField<DIM, tSpaceVector, tSpaceMatrix, tView>;
	inline static ScalarField scalarField = ScalarField(MergeDx, IsSplitting, periodCenter, periodSize, isAxisPeriodic);

	// added scalar
	inline static std::mutex _addedQMutex;
	inline static std::vector<double> _addedQ;

	// variable

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;

			// ---------------- CUSTOM CONSTRAIN START

			tView<tSpaceVector> x(pState);
			x = sp0ce::xPeriodic<tSpaceVector>(x.data(), periodCenter.data(), periodSize.data(), isAxisPeriodic.data());

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

			// physics

			if (HasSource) {
				const double c = tGroupVariable::c(_state.data(), _state.size(), SourceX.data());
				if((SourceC - c) > Cth) {
					addQ(SourceX.data(), SourceS.data(), (SourceC - c) * std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(SourceS.determinant()) * RunParameters::Dt / SourceReactionTime);
				}
			}

			if (not _addedQ.empty()) { // addQ
				_addedQMutex.lock();

				_state.insert(_state.end(), _addedQ.begin(), _addedQ.end());
				_addedQ.clear();
				
				_addedQMutex.unlock();
			}

			// numerics

			if (IsSplitting) {
				std::vector<double> newState;
				newState.reserve(_state.size());

				for(int index = 0; index < tBase::groupSize(_state.size()); ++index) {
					double* pMemberState = tBase::state(_state.data(), index);
					
					tView<tSpaceVector> memberX(pMemberState);
					tView<tSpaceMatrix> memberS(pMemberState + DIM);
					double& memberQ = pMemberState[DIM + DIM * DIM];

					Eigen::SelfAdjointEigenSolver<tSpaceMatrix> solver(memberS);
					const tSpaceVector eigenValues = solver.eigenvalues();
					const tSpaceMatrix eigenVectors = solver.eigenvectors();

					std::vector<double> splitState;

					// add member state to split state
					tBase::pushBackMember(splitState);
					double* pNewState = tBase::state(splitState.data(), tBase::groupSize(splitState.size()) - 1);
					tView<tSpaceVector> newX(pNewState);
					tView<tSpaceMatrix> newS(pNewState + DIM);
					double& newQ = pNewState[DIM + DIM * DIM];
					// set state
					newX = memberX;
					newS = memberS;
					newQ = memberQ;

					for(unsigned int i = 0; i < DIM; ++i) {
						double variance = eigenValues[i];
						double standardDeviation = std::sqrt(variance);
						const tSpaceVector varianceDirection = eigenVectors.col(i);

						int nSplits = std::ceil(4.0 / std::pow(SplitDistance, 2) * (variance - std::pow(SplitSize, 2)));

						if (nSplits > 0) {
							// binomial distribution by repeated convolution with [0.5, 0.5] (coin toss)
							// $P(k) = \binom{n}{k} (0.5)^n$ computed as follows :
							// \begin{align}
							// q_0 &= 2^{-n}, \\
							// q_{k+1} &= q_k \cdot \frac{n - k}{k + 1}
							// \end{align}
							std::vector<double> qDistribution(nSplits + 1);
							// index of largest probability
						    const unsigned int kMax = nSplits / 2;
						    // set max probability temporarily to 1.0
						    qDistribution[kMax] = 1.0;
						    // fill upwards: q[k+1] = q[k] * (n-k)/(k+1)
						    for (unsigned int k = kMax; k < nSplits; ++k) {
						        qDistribution[k + 1] = qDistribution[k] * static_cast<double>(nSplits - k) / static_cast<double>(k + 1);
						    }
						    // fill downwards: q[k-1] = q[k] * k / (n-k+1)
						    for (int k = kMax; k > 0; --k) {
						        qDistribution[k - 1] = qDistribution[k] * static_cast<double>(k) / static_cast<double>(nSplits - k + 1);
						    }
						
						    // normalize
						    const double sum = std::accumulate(qDistribution.begin(), qDistribution.end(), 0.0);
						    for (auto &q : qDistribution) q /= sum;
						    
						    // set split state
							std::vector<double> newSplitState(tBase::groupSize(splitState.size()) * qDistribution.size() * StateSize);
							for(unsigned int splitMemberIndex = 0; splitMemberIndex < tBase::groupSize(splitState.size()); ++splitMemberIndex) {

								double* pSplitMemberState = tBase::state(splitState.data(), splitMemberIndex);

								tView<tSpaceVector> splitMemberX(pSplitMemberState);
								tView<tSpaceMatrix> splitMemberS(pSplitMemberState + DIM);
								double& splitMemberQ = pSplitMemberState[DIM + DIM * DIM];

								const tSpaceVector splitX = splitMemberX;
								const tSpaceMatrix splitS = splitMemberS - nSplits * 0.25 * std::pow(SplitDistance, 2) * varianceDirection * varianceDirection.transpose();

								// add a member
							
								for(unsigned int k = 0; k < qDistribution.size(); ++k) {
									// set state
									double* pPartState = tBase::state(newSplitState.data(), splitMemberIndex * qDistribution.size() + k);
									// x
									tView<tSpaceVector> partX(pPartState);
									tView<tSpaceMatrix> partS(pPartState + DIM);
									double& partQ = pPartState[DIM + DIM * DIM];
				
									partX = splitX + SplitDistance * (k - (qDistribution.size() - 1)/2.0) * varianceDirection;
									partS = splitS;
									partQ = splitMemberQ * qDistribution[k];
								}
							}
							splitState = newSplitState;
						}
					}
					
					newState.insert(newState.end(), splitState.begin(), splitState.end());
				}
				
				// merge

				scalarField.prepare0(tBase::cState(newState.data(), 0), tBase::groupSize(newState.size()));
				_state = scalarField.superStateArray[0];

				// filter
				
				newState.clear();
				newState.reserve(_state.size());

				for(int index = 0; index < tBase::groupSize(_state.size()); ++index) {
					double* pMemberState = tBase::state(_state.data(), index);
					
					tView<tSpaceVector> memberX(pMemberState);
					tView<tSpaceMatrix> memberS(pMemberState + DIM);
					double& memberQ = pMemberState[DIM + DIM * DIM];

					if(memberQ > Qth) {
						newState.insert(newState.end(), pMemberState, pMemberState + StateSize);
					} else {
						if(not hasBlobBeenDeleted) {
							std::cout << "INFO: A scalar blob has fallen below the concentration threshold and has been deleted. This message will not be displayed again." << std::endl;
							hasBlobBeenDeleted = true;
						}
					}
				}
				
				scalarField.prepare0(tBase::cState(newState.data(), 0), tBase::groupSize(newState.size()));
				_state = scalarField.superStateArray[0];
			}
			
			// ---------------- CUSTOM CONSTRAIN END
			
		}

		static void addQ(const double* pPosition, const double* pS, const double dQ) {
			// input
			const tView<const tSpaceVector> position(pPosition);
			const tView<const tSpaceMatrix> s(pS);
			// q
			if(dQ != 0.0) {
				_addedQMutex.lock();

				tBase::pushBackMember(_addedQ);

				// set initial state
				double* pNewState = tBase::state(_addedQ.data(), tBase::groupSize(_addedQ.size()) - 1);
				
				tView<tSpaceVector> newX(pNewState);
				tView<tSpaceMatrix> newS(pNewState + DIM);
				double& newQ = pNewState[DIM + DIM * DIM];
				
				// // set
				newX = position;
				newS = s;
				newQ = dQ;

				_addedQMutex.unlock();
			}
		}

		static double c(const double* pState, const unsigned int stateSize, const double* pX) {
			return scalarField.getScalar(tBase::cState(pState, 0), tBase::groupSize(stateSize), pX);
		}

		static tSpaceVector cGradient(const double* pState, const unsigned int stateSize, const double* pX) {
			return scalarField.getGradient(tBase::cState(pState, 0), tBase::groupSize(stateSize), pX);
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
			// // output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceMatrix> dS(dState.data() + DIM);
			double& dQ = dState[DIM + DIM * DIM];

			dX = u;
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
			
			scalarField.prepare(tGroupVariable::cState(pState, 0), tGroupVariable::groupSize(stateSize));

			// ---------------- CUSTOM PREPARATION END
		}
	};
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START
	
	// ---------------- CUSTOM INIT PARAMETERS END

	static void init(std::vector<double>& state) {
		// ---------------- CUSTOM INIT START

		const double dtMax = std::pow(EnvParameters::cLength/2.0, 2) / Diffusivity;
		std::cout << "INFO: " << name << ", Maximum Dt: " << dtMax << std::endl;
		std::cout << "INFO: " << name << ", Maximum SplitSize: " << EnvParameters::cLength << std::endl;
		if (RunParameters::Dt > dtMax) {
			std::cout << "WARNING: " << name << ", RunParameters::Dt " << RunParameters::Dt << " > Maximum Dt " << dtMax << ". Consider decreasing RunParameters::Dt to be smaller than Maximum Dt" << std::endl;
		}
		if (SplitSize > EnvParameters::cLength) {
			std::cout << "WARNING: " << name << ", SplitSize " << SplitSize << " > EnvParameters::cLength " << EnvParameters::cLength << ". Consider decreasing SplitSize to be smaller than EnvParameters::cLength." << std::endl;
		}

		if (HasInit) { // 0
			tGroupVariable::pushBackMember(state);
			// set initial state
			double* pState = tGroupVariable::state(state.data(), tGroupVariable::groupSize(state.size()) - 1);
			// define
			tView<tSpaceVector> x(pState);
			tView<tSpaceMatrix> s(pState + DIM);
			double& q = pState[DIM + DIM * DIM];
			// set
			x = InitX;
			s = InitS;
			q = InitC * (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(s.determinant()));
		}
		
		// ---------------- CUSTOM INIT END
	}

	// ---------------- CUSTOM POST PARAMETERS START

	inline static const bool IsPostProcessingParticles = false;
	inline static const bool IsPostProcessingConcentration = true && IsPostProcessingParticles;
	inline static const bool IsPostProcessingConcentrationOnGrid = true;
	inline static const unsigned int GridN = 128;

	// ---------------- CUSTOM POST PARAMETERS START

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		scalarField.prepare(tGroupVariable::cState(pState, 0), tGroupVariable::groupSize(stateSize));

		if(IsPostProcessingParticles) { // particles
			unsigned int number = tVariable::groupSize(stateSize);
			unsigned int formatNumber = int(std::log10(number)) + 1;
			
			for(unsigned int index = 0; index < number; ++index) {
				const double* pMemberState = tVariable::cState(pState, index);
				// input
				const tView<const tSpaceVector> x(pMemberState);
				const tView<const tSpaceMatrix> s(pMemberState + DIM);
				const double& q = pMemberState[DIM + DIM * DIM];
				// generate formated index
				std::ostringstream ossIndex;
				ossIndex << "passive_scalar_blobs__index_" << std::setw(formatNumber) << std::setfill('0') << index;
				// output
				for(unsigned int i = 0; i < DIM; ++i) {
					output[ossIndex.str() + "__pos_" + std::to_string(i)] = x[i];
					for(unsigned int j = 0; j < DIM; ++j) {
						output[ossIndex.str() + "__s_" + std::to_string(i) + "_" + std::to_string(j)] = s(i, j);
					}
				}
				output[ossIndex.str() + "__c0"] = q / (std::pow(2.0 * M_PI, DIM/2.0) * std::sqrt(s.determinant()));
				if(IsPostProcessingConcentration) {
					output[ossIndex.str() + "__c"] = tGroupVariable::c(pState, stateSize, x.data());
				}
			}
		}

		if(IsPostProcessingConcentrationOnGrid) { // profile
			const unsigned int formatNumber = int(std::log10(GridN)) + 1;

			const double dx = EnvParameters::cDomainSize[0]/GridN;
			const double dy = EnvParameters::cDomainSize[1]/GridN;
			
			for(unsigned int i = 0; i < GridN; ++i) {
				for(unsigned int j = 0; j < GridN; ++j) {
					tSpaceVector x = tSpaceVector::Zero();
					x[0] = -0.5 * EnvParameters::cDomainSize[0] + EnvParameters::cDomainCenter[0] + i * dx;
					x[1] = -0.5 * EnvParameters::cDomainSize[1] + EnvParameters::cDomainCenter[1] + j * dy;
					// generate formated i and j
					std::ostringstream ossIndex;
					ossIndex << "grid_c__i_" << std::setw(formatNumber) << std::setfill('0') << i << "_j_" << std::setw(formatNumber) << std::setfill('0') << j;
					// output
					output[ossIndex.str() + "__x"] = x[0];
					output[ossIndex.str() + "__y"] = x[1];
					output[ossIndex.str() + "__c"] = tGroupVariable::c(pState, stateSize, x.data());
					output[ossIndex.str() + "__n"] = tVariable::groupSize(stateSize);
				}
			}
		}
		
		// ---------------- CUSTOM INIT END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
