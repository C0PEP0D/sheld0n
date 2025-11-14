#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

// std includes
#include <array>

namespace c0p {

struct Flow {

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		return tSpaceVector::Zero();
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		return tSpaceMatrix::Zero();
	};
	

	// prepare

	static void prepare(const double t) {
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
