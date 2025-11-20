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
	// concentration threshold (for blob deletion)
	inline static const double Cth = std::pow(2, -32);
	inline static const double Qth = Cth * std::pow(Dx, DIM);

	// source
	static const bool HasSource = true;
	inline static const tSpaceVector SourceX = InitX;
	inline static const double SourceC = InitC;
	inline static const double SourceS = InitS;
	inline static const double SourceReactionTime = 1.0;

	// periodicity (if activated)
	inline static const tSpaceVector periodCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector periodSize = EnvParameters::cDomainSize;
	inline static const std::array<bool, DIM> isAxisPeriodic = EnvParameters::cDomainIsAxisPeriodic;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	// concentration threshold
	inline static bool hasBlobBeenDeleted = false;

	// scalar field
	using ScalarField = pl0f::ScalarField<DIM, tSpaceVector, tSpaceMatrix, tView>;
	inline static ScalarField scalarField = ScalarField(MergeDx, IsSplitting); // swap comments to activate periodicity
	// inline static ScalarField scalarField = ScalarField(MergeDx, IsSplitting, periodCenter, periodSize, isAxisPeriodic); // swap comments to deactivate periodicity

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
			
			if (IsSplitting) {
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

							index -= 1;
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

				scalarField.prepare(tBase::cState(_state.data(), 0), tBase::groupSize(_state.size()));
				_state = scalarField.superStateArray[0];
			}
			// ---------------- CUSTOM CONSTRAIN END
			
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
			
			scalarField.prepare(tGroupVariable::cState(pState, 0), tGroupVariable::groupSize(stateSize));

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
		scalarField.prepare(tGroupVariable::cState(pState, 0), tGroupVariable::groupSize(stateSize));

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
