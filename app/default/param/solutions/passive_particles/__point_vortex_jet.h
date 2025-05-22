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
	// physics parameters
	inline static const double FlowVelocity = 2.0;
	inline static const double DipoleSeparation = std::pow(2, -4) * EnvParameters::cDomainSize[1];
	inline static const tSpaceVector PositivePosition = EnvParameters::cDomainCenter + tSpaceVector({-0.5 * EnvParameters::cDomainSize[0], 0.5 * DipoleSeparation});
	inline static const tSpaceVector NegativePosition = EnvParameters::cDomainCenter + tSpaceVector({-0.5 * EnvParameters::cDomainSize[0], -0.5 * DipoleSeparation});
	// preprocessed quantities
	inline static const double FlowRate = FlowVelocity * DipoleSeparation;
	inline static const double CirculationRate = FlowVelocity * FlowVelocity;
	// numeric parameters
	inline static const double Circulation = FlowRate / 1.0; // increase the divider to increase the "resolution" of the jet
	inline static const double VortexRate = CirculationRate / Circulation;
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
	
	// creating tVariable and tEquation
	using tMetaVariable = d0t::VariableVector<tVector, tView, 1>; // stores timer
	struct tVariable : public d0t::VariableGroupDynamic<tSubVariable, tMetaVariable> {
		using tBase = d0t::VariableGroupDynamic<tSubVariable, tMetaVariable>;

		static void constrain(std::vector<double>& p_state) {
			tBase::_constrain(p_state);
			// ---------------- CUSTOM CONSTRAIN START
			// remove points that get out of domain
			for(int index = tBase::groupSize(p_state.size()) - 1; index > -1; index--) {
				const double* pState = tBase::cState(p_state.data(), index);
				const tView<const tSpaceVector> x(pState);
				if (
					std::abs(x[0] - EnvParameters::cDomainCenter[0]) > 0.5 * EnvParameters::cDomainSize[0] || 
					std::abs(x[1] - EnvParameters::cDomainCenter[1]) > 0.5 * EnvParameters::cDomainSize[1]
				) {
					tBase::eraseMember(p_state, index);
				}
			}
			// add points based on rate
			double* pTime;
			pTime = tBase::stateMeta(p_state.data());
			const unsigned int number = int((*pTime) * VortexRate);
			if (number > 0) {
				_spawn(p_state, number);
				// update pTime before set
				pTime = tBase::stateMeta(p_state.data());
				*pTime = 0.0;
			}
			// ---------------- CUSTOM CONSTRAIN END
		}
		
		static void _spawn(std::vector<double>& p_state, unsigned int number) {
			for (unsigned int index = 0; index < number; index++) {
				{ // positive
					tBase::pushBackMember(p_state);
					// set initial state
					double* pState = tBase::state(p_state.data(), tBase::groupSize(p_state.size()) - 1);
					tView<tSpaceVector> x(pState);
					double* pCirculation = pState + DIM;
					// // set
					x = PositivePosition;
					*pCirculation = Circulation;
				}
				{ // negative
					tBase::pushBackMember(p_state);
					// set initial state
					double* pState = tBase::state(p_state.data(), tBase::groupSize(p_state.size()) - 1);
					tView<tSpaceVector> x(pState);
					double* pCirculation = pState + DIM;
					// // set
					x = NegativePosition;
					*pCirculation = -Circulation;
				}
			}
		}
	};
	struct tEquation : public d0t::EquationGroupDynamic<tVariable, tSubEquation> {
	
		using tBase = d0t::EquationGroupDynamic<tVariable, tSubEquation>;
	
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			tBase::prepare(pState, stateSize, t);
			// prepare flow
			Flow::prepare(tVariable::cState(pState, 0), tVariable::groupSize(stateSize));
		}

		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {
			tStateVectorDynamic dState = tBase::stateTemporalDerivative(pState, stateSize, t);
			// meta
			double* pDTime = tVariable::stateMeta(dState.data());
			*pDTime = 1.0;
			// return
			return dState;
		}
	};

	// ---------------- CUSTOM INIT PARAMETERS START
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(std::vector<double>& p_state) {
		// ---------------- CUSTOM INIT START
		double* pTime = tVariable::stateMeta(p_state.data());
		*pTime = 1.0/VortexRate;
		// ---------------- CUSTOM INIT END
	}

	static std::map<std::string, tScalar> post(const double* pState, const unsigned int stateSize, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM INIT START
		unsigned int number = tVariable::groupSize(stateSize);
		unsigned int formatNumber = number/10 + 1;
		tSpaceVector xAverage = tSpaceVector::Zero();
		for(unsigned int subIndex = 0; subIndex < number; ++subIndex) {
			const double* pSubState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pSubState);
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
