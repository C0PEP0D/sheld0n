#ifndef C0P_SOLUTIONS_GROUP_OF_POINTS_CUSTOM_PARAMETERS_H
#define C0P_SOLUTIONS_GROUP_OF_POINTS_CUSTOM_PARAMETERS_H
#pragma once

// app includes
#include "core/solutions/prop.h"
#include "core/solutions/core.h"
#include "param/flow/choice.h"

#include "core/solutions/equation/custom/prop.h"
#include "param/parameters.h"

// include lib
#include "d0t/equations/advection.h"

namespace c0p {

struct _GroupOfPointsCustomParameters {
	inline static std::string name = "group_of_points";

	// ---------------- CUSTOM EQUATION PARAMETERS START
	static const unsigned StateSize = DIM; // Dimension of the state variable 
	// Feel free to add parameters if you need
	static const unsigned Number = EnvParameters::cGroupSize; // Number of members in the group
	// ---------------- CUSTOM EQUATION PARAMETERS END

	// definition of the member data
	using tSubVariable = d0t::VariableComposed<d0t::VariableVector<tVector, tView, StateSize>>;
	struct tSubEquation : public d0t::Equation<tSubVariable> {
		static tStateVectorDynamic stateTemporalDerivative(const double* pState, const unsigned int stateSize, const double t) {

			// ---------------- CUSTOM EQUATION START
			// initializing output
			tStateVectorDynamic output = tStateVectorDynamic::Zero(tVariable::Size);
			// interpret output as a tSpaceVector
			tView<tSpaceVector> dX(output.data());
			// interpret input as a tSpaceVector
			const tView<const tSpaceVector> x(output.data());
			// get flow velocity
			const tSpaceVector u = Flow::getVelocity(x.data(), t);
			// define the temporal derivative of the state
			dX = u; // example : simple advection equation
			// ---------------- CUSTOM EQUATION END

			// return result
			return output;
		}
	};
	// creating tVariable and tEquation
	using tVariable = d0t::VariableGroupStatic<tSubVariable, Number>;
	using tEquation = d0t::EquationGroupStatic<tVariable, tSubEquation>;

	// ---------------- CUSTOM INIT PARAMETERS START
	static constexpr std::array<double, DIM> BoxCenter = {0.0, 0.0}; // defined for 2D simulation, use {0.0, 0.0, 0.0} for 3D
	static constexpr std::array<double, DIM> BoxSize = {2.0 * M_PI, 2.0 * M_PI}; // defined for 2D simulation, use {2.0 * M_PI, 2.0 * M_PI,  2.0 * M_PI} for 3D
	// ---------------- CUSTOM INIT PARAMETERS START

	static void init(double* pState) {
		// ---------------- CUSTOM INIT START
		// interpret BoxCenter and BoxSize as vectors
		const tSpaceVector boxCenter = tView<const tSpaceVector>(BoxCenter.data());
		const tSpaceVector boxSize = tView<const tSpaceVector>(BoxSize.data());
		// loop over each member of the variable group
		for(unsigned int subIndex = 0; subIndex < Number; ++subIndex) {
			// get the state variable of the subIndex member of the group
			double* pSubState = tVariable::state(pState, subIndex);
			// interpret subState as a tSpaceVector
			tView<tSpaceVector> x(pSubState);
			// set the initial position of this member
			x = boxCenter + 0.5 * boxSize.asDiagonal() * tSpaceVector::Random();
		}
		// ---------------- CUSTOM INIT END
	}
};

}

#endif
