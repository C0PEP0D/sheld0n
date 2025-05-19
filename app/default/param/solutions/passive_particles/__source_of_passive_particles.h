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
	static constexpr double Rate = 128.0;
	static constexpr double Lifetime = 1.0;
	inline static const tSpaceVector Center = EnvParameters::cDomainCenter;
	inline static const tSpaceVector Length = EnvParameters::cDomainSize;
	// ---------------- CUSTOM EQUATION PARAMETERS END

	struct tSubVariable : public d0t::VariableVector<tVector, tView, StateSize> {
	
		static void constrain(double* pState) {
			// ---------------- CUSTOM CONSTRAIN START
			// ---------------- CUSTOM CONSTRAIN END
		}

	};

	struct tSubEquation : public d0t::Equation<tSubVariable> {

		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			// ---------------- CUSTOM PREPARATION START
			const tView<const tSpaceVector> cX(pState);
			Flow::prepareVelocity(cX.data(), t);
			// ---------------- CUSTOM PREPARATION END
		}
	
		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
			tStateVectorDynamic dState = tStateVectorDynamic::Zero(tVariable::Size);

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
	
	// creating tVariable and tEquation
	struct tVariable : public d0t::VariableGroupDynamic<tSubVariable> {
		using tBase = d0t::VariableGroupDynamic<tSubVariable>;

		static void constrain(std::vector<double>& p_state) {
			tBase::_constrain(p_state);
			// ---------------- CUSTOM CONSTRAIN START
			// remove dead points
			for(int index = tBase::groupSize(p_state.size()) - 1; index > -1; index--) {
				const double* pState = tBase::cState(p_state.data(), index);
				const double tLife = *(pState + DIM);
				if (tLife < 0.0) {
					tBase::eraseMember(p_state, index);
				}
			}
			// add points based on rate
			if (p_state.empty()) {
				_spawn(1);
			} else {
				const double* pStateLast = tBase::cState(p_state.data(), tBase::groupSize(p_state.size()) - 1);
				const double tLifeLast = *(pStateLast + DIM);
				const unsigned int number = int((Lifetime - tLifeLast) * Rate);
				if (number > 0) {
					_spawn(number);
				}
			}
			// ---------------- CUSTOM CONSTRAIN END
		}
		
		static void _spawn(unsigned int number) {
			for (unsigned int index = 0; index < number; index++) {
				tBase::pushBackMember(p_state);
				// set initial state
				double* pState = tBase::state(p_state.data(), tBase::groupSize(p_state.size()) - 1);
				tView<tSpaceVector> x(pState);
				double* pTLife = pState + DIM;
				// // set
				x = tSpaceVector::Random();
				for(unsigned int index = 0; index < DIM; ++index){
					x[index] = x[index] * Length[index] + Center[index];
				}
				*pTLife = Lifetime;
			}
		}
	}
	using tEquation = d0t::EquationGroupDynamic<tVariable, tSubEquation>;

	// ---------------- CUSTOM INIT PARAMETERS START
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START
		// ---------------- CUSTOM INIT END
	}

	// static constexpr unsigned FormatNumber = std::ceil(Number/10.0); // compatibility issue with Clang
	static constexpr unsigned FormatNumber = Number/10 + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			const double* pSubState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pSubState);
			const double tLife = *(pSubState + DIM);
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(FormatNumber) << std::setfill('0') << subIndex;
			// output
			output[ossIndex.str() + "__pos_0"] = x[0];
			output[ossIndex.str() + "__pos_1"] = x[1];
			output[ossIndex.str() + "__tlife"] = tLife;
			// compute average
			xAverage += x;
		}
		xAverage /= Number;
		output["passive_particles__average_pos_0"] = xAverage[0];
		output["passive_particles__average_pos_1"] = xAverage[1];
		// ---------------- CUSTOM INIT END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
