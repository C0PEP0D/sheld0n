#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>
#include <iomanip>

// lib includes
#include "d0t/variables/curve.h"

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"

// FLAG: DYNAMIC

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static constexpr unsigned int Density = 16;
	static constexpr bool IsClosed = false;
	static constexpr unsigned int InterpolationOrder = 2;
	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[StateIndex].data() + memberStateIndex;
			// ---------------- CUSTOM CONSTRAIN START
			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	using tCurveVariable = d0t::VariableCurve<tMemberVariable, Density, IsClosed, InterpolationOrder>;
	using tVariable = tCurveVariable;

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
			const double* pState = tCurveVariable::cState(pStateArray[StateIndex], memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START
			// input
			const tView<const tSpaceVector> x(pState);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// output
			tView<tSpaceVector> dX(dState.data());
			// equation
			dX = u;
			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}

	};
	using tCurveEquation = d0t::EquationGroupDynamic<tCurveVariable, tMemberEquation>;
	using tEquation = tCurveEquation;

	// ---------------- CUSTOM INIT PARAMETERS START
	inline static const tSpaceVector InitPositionStart = EnvParameters::cDomainCenter - 0.25 * tSpaceVector({EnvParameters::cDomainSize[0], 0.0});
	inline static const tSpaceVector InitPositionEnd = EnvParameters::cDomainCenter + 0.25 * tSpaceVector({EnvParameters::cDomainSize[0], 0.0});
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(std::vector<double>& p_state) {
		// ---------------- CUSTOM INIT START
		const tSpaceVector step = (InitPositionEnd - InitPositionStart) / InterpolationOrder;
		for(unsigned int i = 0; i < InterpolationOrder + 1; ++i) {
			tVariable::pushBackMember(p_state);
			// set initial state
			double* pState = tVariable::state(p_state.data(), tVariable::groupSize(p_state.size()) - 1);
			tView<tSpaceVector> x(pState);
			// // set
			x = InitPositionStart + i * step;
		}
		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		unsigned int number = tVariable::groupSize(stateSize);
		unsigned int formatNumber = number/10 + 1;
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < number; ++subIndex) {
			const double* pMemberState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pMemberState);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(formatNumber) << std::setfill('0') << subIndex;
			// output
			output[ossIndex.str() + "__pos_0"] = x[0];
			output[ossIndex.str() + "__pos_1"] = x[1];
			// compute average
			xAverage += x;
		}
		xAverage /= number;
		output["passive_particles__average_pos_0"] = xAverage[0];
		output["passive_particles__average_pos_1"] = xAverage[1];
		// ---------------- CUSTOM INIT END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
