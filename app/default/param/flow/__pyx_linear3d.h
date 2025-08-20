#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

// cython
#include "param/flow/parameters_flow.h"

namespace c0p {

struct Flow {

	static void init() {
		flow_parameters();
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		// input
		const tView<const tSpaceVector> x(pX);
		// output
		const tSpaceVector u;

		// cython
		flow_get_velocity(x, t, u);
		
		return u;
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		// input
		const tView<const tSpaceVector> x(pX);
		// output
		const tSpaceVector j;

		// cython
		flow_get_velocity_gradients(x, t, j);
		
		return j;
	};
	
	// prepare

	template<typename tEquationStatic, typename tEquationFlow>
	static void prepare(const double* pState, const unsigned int stateSize, const double t) {
		// nothing to do
	}

	static void prepareVelocity(const double* pX, const double t) {
		// nothing to do
	}

	static void prepareVelocityGradients(const double* pX, const double t) {
		// nothing to do
	}
};

}

#endif
