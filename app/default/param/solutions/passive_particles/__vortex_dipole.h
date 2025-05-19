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

namespace c0p {

struct _PassiveParticlesParameters {
	inline static unsigned int StateIndex = 0; // USED INTERNALLY, DO NOT EDIT
	inline static std::string name = "passive_particles";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM + 1; // dimension of the state variable 
	// feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // number of members in the group
	static constexpr double InitVorticity = 1.0/Number;
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
			const double w = pState[DIM];
			// output
			tView<tSpaceVector> dX(dState.data());
			dX = u;
			// ---------------- CUSTOM EQUATION END

			// return result
			return dState;
		}
	};
	// creating tVariable and tEquation
	using tVariable = d0t::VariableGroupStatic<d0t::VariableComposed<tSubVariable>, Number>;
	struct tEquation : public d0t::EquationGroupStatic<tVariable, tSubEquation> {

		using tBase = d0t::EquationGroupStatic<tVariable, tSubEquation>;
	
		static void prepare(const double* pState, const unsigned int stateSize, const double t) {
			tBase::prepare(pState, stateSize, t);
			// prepare flow
			Flow::prepare(pState, stateSize/StateSize);
		}
	};

	// ---------------- CUSTOM INIT PARAMETERS START
	inline static const tSpaceVector Center = EnvParameters::cDomainCenter;
	inline static const double Radius = 0.125 * EnvParameters::cDomainSize[1];
	inline static const double Spacing = 0.75 * EnvParameters::cDomainSize[1];
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START
		// loop over each member of the variable group
		const unsigned int halfNumber = Number / 2;
		for(unsigned int index = 0; index < halfNumber; ++index) {
			// get the state variable of the index member of the group
			double* pSubState = tVariable::state(pState, index);
			// interpret subState as a tSpaceVector
			tView<tSpaceVector> x(pSubState);
			double& w = pSubState[DIM];
			// set the initial position of this member
			x = Center + tSpaceVector({0.0, 0.5 * Spacing}) + Radius * tSpaceVector({
				std::cos(index * 2 * M_PI / halfNumber), 
				std::sin(index * 2 * M_PI / halfNumber)
			});
			w = InitVorticity;
		}
		for(unsigned int index = 0; index < (Number - halfNumber); ++index) {
			// get the state variable of the index member of the group
			double* pSubState = tVariable::state(pState, index + halfNumber);
			// interpret subState as a tSpaceVector
			tView<tSpaceVector> x(pSubState);
			double& w = pSubState[DIM];
			// set the initial position of this member
			x = Center - tSpaceVector({0.0, 0.5 * Spacing}) + Radius * tSpaceVector({
				std::cos(index * 2 * M_PI / (Number - halfNumber)), 
				std::sin(index * 2 * M_PI / (Number - halfNumber))
			});
			w = -InitVorticity;
		}
		// ---------------- CUSTOM INIT END
	}

	// static constexpr unsigned FormatNumber = std::ceil(Number/10.0); // compatibility issue with Clang
	static constexpr unsigned FormatNumber = Number/10 + 1;

	static std::map<std::string, tScalar> post(const double* pState, const double t) {
		std::map<std::string, double> output;
		// ---------------- CUSTOM POST START
		tSpaceVector xAverage = tSpaceVector::Zero();
		double wAverage = 0.0;
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			const double* pSubState = tVariable::cState(pState, subIndex);
			// input
			const tView<const tSpaceVector> x(pSubState);
			const double w = pSubState[DIM];
			// generate formated index
			std::ostringstream ossIndex;
			ossIndex << "passive_particles__index_" << std::setw(FormatNumber) << std::setfill('0') << subIndex;
			// output
			output[ossIndex.str() + "__pos_0"] = x[0];
			output[ossIndex.str() + "__pos_1"] = x[1];
			output[ossIndex.str() + "__vorticity"] = w;
			// compute average
			xAverage += x;
			wAverage += w;
		}
		xAverage /= Number;
		wAverage /= Number;
		output["passive_particles__average_pos_0"] = xAverage[0];
		output["passive_particles__average_pos_1"] = xAverage[1];
		output["passive_particles__average_vorticity"] = wAverage;
		// ---------------- CUSTOM POST END
		return output;
	}
};

using _PassiveParticles = EquationCustom<_PassiveParticlesParameters>;

}

#endif
