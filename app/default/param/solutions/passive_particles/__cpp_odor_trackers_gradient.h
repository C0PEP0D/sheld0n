#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"

// FLAG: INCLUDE OTHER SOLUTION START
#include "param/solutions/passive_scalar_blobs/parameters.h"
// FLAG: INCLUDE OTHER SOLUTION END
#include "param/run/parameters.h"

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START

	static const unsigned StateSize = DIM + DIM; // dimension of the state variable
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	static constexpr double SwimmingVelocity = 0.5;
	static constexpr double ReactionTime = 1.0/128.0;

	// ---------------- CUSTOM EQUATION PARAMETERS END

	// variable

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[0].data() + memberStateIndex;

			// ---------------- CUSTOM CONSTRAIN START

			tView<tSpaceVector> x(pState);
			tView<tSpaceVector> p(pState + DIM);

			p = p.normalized();

			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	using tGroupVariable = d0t::VariableGroupStatic<d0t::VariableComposed<tMemberVariable>, Number>;
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
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[0] + StateIndex, memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// input
			const tView<const tSpaceVector> x(pState);
			const tView<const tSpaceVector> p(pState + DIM);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// odor
			using PassiveScalarBlobsParameters = _PassiveScalarBlobsParameters;
			const double* pPassiveScalarBlobsState  = pStateArray[PassiveScalarBlobsParameters::StateIndex];
			const unsigned int PassiveScalarBlobsSize  = pStateSize[PassiveScalarBlobsParameters::StateIndex];
			// // input gradient
			const tSpaceVector cGradient = PassiveScalarBlobsParameters::tVariable::cGradient(pPassiveScalarBlobsState, PassiveScalarBlobsSize, x.data());
			const double cGradientNorm = cGradient.norm();
			// output
			tView<tSpaceVector> dX(dState.data());
			tView<tSpaceVector> dP(dState.data() + DIM);
			// equation
			dX = u + p.normalized() * SwimmingVelocity;
			if(cGradientNorm > 0.0) {
				const tSpaceVector cGradientNormalized = cGradient / cGradientNorm;
				dP = (cGradientNormalized - p) * cGradientNorm / ReactionTime;
			} else {
				dP = tSpaceVector::Zero();
			}

			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}

	};
	using tGroupEquation = d0t::EquationGroupStatic<tGroupVariable, tMemberEquation>;
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START

	inline static const tSpaceVector BoxCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector BoxSize = EnvParameters::cDomainSize;

	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START

		// loop over each member of the variable group
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			// get the state variable of the subIndex member of the group
			double* pMemberState = tVariable::state(pState, subIndex);
			// interpret subState as a tSpaceVector
			tView<tSpaceVector> x(pMemberState);
			tView<tSpaceVector> p(pMemberState + DIM);
			// set the initial position of this member
			x = BoxCenter + 0.5 * BoxSize.asDiagonal() * tSpaceVector::Random();
			p = tSpaceVector::Random().normalized();
		}

		// ---------------- CUSTOM INIT END
	}

	inline static const unsigned int FormatNumber = int(std::log10(Number)) + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;

		// ---------------- CUSTOM POST START
		
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			const double* pSubState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pSubState);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(FormatNumber) << std::setfill('0') << subIndex;
			// output
			for(unsigned int i = 0; i < DIM; ++i) {
				output[ossIndex.str() + "__pos_" + std::to_string(i)] = x[i];
			}
			// compute average
			xAverage += x;
		}
		xAverage /= Number;
		for(unsigned int i = 0; i < DIM; ++i) {
			output["passive_particles__average_pos_" + std::to_string(i)] = xAverage[i];
		}

		// ---------------- CUSTOM POST END
		
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
