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

// FLAG: DYNAMIC

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START

	static const unsigned StateSize = DIM + 1; // dimension of the state variable 
	// feel free to add parameters if you need
	static constexpr double Rate = 256.0;
	static constexpr double Lifetime = 1.0;
	inline static const tSpaceVector Center = EnvParameters::cDomainCenter;
	inline static const tSpaceVector Length = EnvParameters::cDomainSize;

	// ---------------- CUSTOM EQUATION PARAMETERS END

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

			// remove dead points
			for(int index = tBase::groupSize(_state.size()) - 1; index > -1; index--) {
				const double* pState = tBase::cState(_state.data(), index);
				const double tLife = *(pState + DIM);
				if (tLife < 0.0) {
					tBase::eraseMember(_state, index);
				}
			}
			// add points based on rate
			if (_state.empty()) {
				_spawn(_state, 1);
			} else {
				const double* pStateLast = tBase::cState(_state.data(), tBase::groupSize(_state.size()) - 1);
				const double tLifeLast = *(pStateLast + DIM);
				const unsigned int number = int((Lifetime - tLifeLast) * Rate);
				if (number > 0) {
					_spawn(_state, number);
				}
			}

			// ---------------- CUSTOM CONSTRAIN END
		}
		
		static void _spawn(std::vector<double>& _state, unsigned int number) {
			for (unsigned int index = 0; index < number; index++) {
				tBase::pushBackMember(_state);
				// set initial state
				double* pState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);
				tView<tSpaceVector> x(pState);
				double* pTLife = pState + DIM;
				// // set
				x = tSpaceVector::Random();
				for(unsigned int index = 0; index < DIM; ++index){
					x[index] = x[index] * 0.5 * Length[index] + Center[index];
				}
				*pTLife = Lifetime;
			}
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
			const unsigned int stateSize = tMemberVariable::Size;
			const double* pState = tGroupVariable::cState(pStateArray[StateIndex], memberIndex);
			// output
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tMemberVariable::Size);

			// ---------------- CUSTOM EQUATION START

			// input
			const tView<const tSpaceVector> x(pState);
			const double tLife = *(pState + DIM);
			// flow
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// output
			tView<tSpaceVector> dX(dState.data());
			double* pDtLife = dState.data() + DIM;
			// equation
			dX = u;
			*pDtLife = -1.0;

			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}

	};
	using tGroupEquation = d0t::EquationGroupDynamic<tVariable, tMemberEquation>;
	using tEquation = tGroupEquation;

	// ---------------- CUSTOM INIT PARAMETERS START

	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(std::vector<double>& p_state) {

		// ---------------- CUSTOM INIT START

		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;

		// ---------------- CUSTOM INIT START

		unsigned int number = tVariable::groupSize(stateSize);
		unsigned int formatNumber = int(std::log10(number)) + 1;
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < number; ++subIndex) {
			const double* pMemberState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pMemberState);
			const double tLife = *(pMemberState + DIM);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(formatNumber) << std::setfill('0') << subIndex;
			// output
			output[ossIndex.str() + "__pos_0"] = x[0];
			output[ossIndex.str() + "__pos_1"] = x[1];
			output[ossIndex.str() + "__tlife"] = tLife;
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
