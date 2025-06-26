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

#include "param/solutions/ifs_particles/parameters.h"
#include "param/run/parameters.h"

// FLAG: DYNAMIC

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT MANUALLY UNLESS YOU KNOW WHAT YOU ARE DOING
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM + 1; // dimension of the state variable 
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
			std::vector<double>& _state = stateArray[StateIndex];

			// ---------------- CUSTOM CONSTRAIN START

			// // remove points that get out of domain
			// for(int index = tBase::groupSize(_state.size()) - 1; index > -1; index--) {
			// 	const double* pState = tBase::cState(_state.data(), index);
			// 	const tView<const tSpaceVector> x(pState);
			// 	if (
			// 		std::abs(x[0] - EnvParameters::cDomainCenter[0]) > 0.5 * EnvParameters::cDomainSize[0] || 
			// 		std::abs(x[1] - EnvParameters::cDomainCenter[1]) > 0.5 * EnvParameters::cDomainSize[1]
			// 	) {
			// 		tBase::eraseMember(_state, index);
			// 	}
			// }

			// merge points that are too close to each other

			_state = Flow::flow.superVortexStateArray[0];

			// ifs particles

			using IfsParticlesParameters = _IfsParticlesParameters;
			const double* pIfsParticlesState = stateArray[0].data() + IfsParticlesParameters::StateIndex;
			
			for(unsigned int index = 0; index < IfsParticlesParameters::Number; ++index) {
			
				const double* pState = IfsParticlesParameters::tGroupVariable::cState(pIfsParticlesState, index);

				// input
				const tView<const tSpaceVector> x(pState);
				const tView<const tSpaceVector> v(pState + DIM);
				// flow
				const tSpaceVector u = Flow::getVelocity(x.data(), t);
	
				// apply "force" on flow
				const tSpaceVector dVelocity = -(u - v) * (u - v).norm() / IfsParticlesParameters::Width * RunParameters::Dt;
				addVelocity(_state, x.data(), dVelocity.data(), IfsParticlesParameters::Width);
				
			}

			// ---------------- CUSTOM CONSTRAIN END
		}
		
		static void addVelocity(std::vector<double>& _state, const double* pPosition, const double* pDVelocity, const double spacing) {
			// input
			const tView<const tSpaceVector> position(pPosition);
			const tView<const tSpaceVector> dVelocity(pDVelocity);
			const double dVelocityNorm = dVelocity.norm();
			if(dVelocityNorm > 0.0) {
				const tSpaceVector dVelocityDirection = dVelocity / dVelocityNorm;
				const tSpaceVector dVelocityOrthogonal = tSpaceVector({-dVelocityDirection[1], dVelocityDirection[0]});
				// circulation
				const double dCirculation = 0.5 * M_PI * spacing * dVelocityNorm; // constrain needs t
				{ // positive
					tBase::pushBackMember(_state);
					// set initial state
					double* pState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);
					tView<tSpaceVector> x(pState);
					double* pCirculation = pState + DIM;
					// // set
					x = position + 0.5 * spacing * dVelocityOrthogonal;
					*pCirculation = dCirculation;
				}
				{ // negative
					tBase::pushBackMember(_state);
					// set initial state
					double* pState = tBase::state(_state.data(), tBase::groupSize(_state.size()) - 1);
					tView<tSpaceVector> x(pState);
					double* pCirculation = pState + DIM;
					// // set
					x = position - 0.5 * spacing * dVelocityOrthogonal;
					*pCirculation = -dCirculation;
				}
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
	struct tGroupEquation : public d0t::EquationGroupDynamic<tGroupVariable, tMemberEquation> {
	
		using tBase = d0t::EquationGroupDynamic<tVariable, tMemberEquation>;
	
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			tBase::prepare(pState, stateSize, t);
			// prepare flow
			Flow::prepare(tVariable::cState(pState, 0), tVariable::groupSize(stateSize));
		}
	};
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
