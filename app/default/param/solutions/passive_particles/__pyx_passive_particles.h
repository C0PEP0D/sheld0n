#ifndef C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_PASSIVE_PARTICLES_CUSTOM_PARAMETERS_H
#pragma once

// std includes
#include <map>

// app includes
#include "core/solutions/core.h"
#include "param/flow/parameters.h"

#include "core/solutions/equation/custom/core.h"
#include "param/parameters.h"

// cython
#include "param/solutions/passive_particles/parameters_passive_particles.h"

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tMemberVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(std::vector<std::vector<double>>& stateArray, const double t, const unsigned int memberStateIndex) {
			// input
			double* pState = stateArray[0].data() + memberStateIndex;

			// ---------------- CUSTOM CONSTRAIN START

			// input and output
			tView<tSpaceVector> x(pState);
			// cython
			passive_particles_constrain(t, x);
			
			// ---------------- CUSTOM CONSTRAIN END
		}

	};
	using tGroupVariable = d0t::VariableGroupStatic<d0t::VariableComposed<tMemberVariable>, Number>;
	using tVariable = tGroupVariable;

	struct tMemberEquation : public d0t::Equation<tMemberVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {

			// ---------------- CUSTOM PREPARATION START

			// input
			const tView<const tSpaceVector> x(pState);
			// cython
			passive_particles_prepare(x, t);
			
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
			// output
			tView<tSpaceVector> dx(dState.data());

			// cython
			passive_particles_state_temporal_derivative(x, t, dx);
	
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

		passive_particles_parameters();

		// input
		std::vector<tView<tSpaceVector>> xArray;
		xArray.reserve(Number);
		for(unsigned int index = 0; index < Number; ++index) {
			xArray.emplace_back(pState + index * StateSize);
		}

		// cython
		passive_particles_init(Number, xArray.data());
		
		// ---------------- CUSTOM INIT END
	}

	inline static unsigned int FormatNumber = int(std::log10(Number)) + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;
		
		// ---------------- CUSTOM POST START

		// input
		std::vector<tView<const tSpaceVector>> xArray;
		xArray.reserve(Number);
		for(unsigned int index = 0; index < Number; ++index) {
			xArray.emplace_back(pState + index * StateSize);
		}

		// cython
		passive_particles_post(xArray.data(), Number, t, output);
		
		// ---------------- CUSTOM POST END

		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
