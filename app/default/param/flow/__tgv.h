#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

namespace c0p {

struct Flow {

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		return tSpaceVector({
				std::cos(pX[0]) * std::sin(pX[1]),
				-std::sin(pX[0]) * std::cos(pX[1])
		});
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		tSpaceMatrix velocityGradients = tSpaceMatrix::Zero();
		velocityGradients(0,0) = -std::sin(pX[0]) * std::sin(pX[1]); velocityGradients(0,1) = std::cos(pX[0]) * std::cos(pX[1]);
		velocityGradients(1,0) = -std::cos(pX[0]) * std::cos(pX[1]); velocityGradients(1,1) = std::sin(pX[0]) * std::sin(pX[1]);
		return velocityGradients;
	};
	
	// prepare

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
