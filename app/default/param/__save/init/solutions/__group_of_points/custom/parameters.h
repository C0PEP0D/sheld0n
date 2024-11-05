#ifndef C0P_PARAM_INIT_SOLUTIONS_GROUP_OF_POINTS_CUSTOM_PARAMETERS_H
#define C0P_PARAM_INIT_SOLUTIONS_GROUP_OF_POINTS_CUSTOM_PARAMETERS_H
#pragma once

// app include
#include "core/init/solutions/equation/prop.h"
#include "param/parameters.h"

namespace c0p {

// Add group members
struct Init_GroupOfPointsCustomParameters {

	static constexpr std::array<double, DIM> Center = {0.0, 0.0};
	static constexpr std::array<double, DIM> Length = {2.0 * M_PI, 2.0 * M_PI};

	static void set(double* pState) {
		// set a random initial state within a bounding box
	    for(unsigned int memberIndex = 0; memberIndex < _GroupOfPoints::tVariable::GroupSize; memberIndex++) {
	    	tSpaceVector xInit = {Center[0], Center[1]};
	    	const tSpaceVector xRandom = tSpaceVector::Random();
	    	for(unsigned int index = 0; index < DIM; index++) {
	    		xInit[index] += 0.5 * Length[index] * xRandom[index];
	    	}
	    	_GroupOfPoints::tVariable::tVariableMember::position(_GroupOfPoints::tVariable::state(pState, memberIndex)) = xInit;
	    }
	};
};

}

#endif
