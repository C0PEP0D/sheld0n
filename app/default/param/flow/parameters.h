#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

namespace c0p {

struct Flow {
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
	
	static tSpaceVector getAcceleration(const double* pX, const double t) {
		return tSpaceVector::Zero();
	};
};

}

#endif
