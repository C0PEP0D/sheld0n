#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

namespace c0p {

struct Flow {

	static constexpr double A = 1.0;
	static constexpr double B = 1.0;
	static constexpr double C = 1.0;

	static void init() {
		// nothing to do
	}

	static tSpaceVector getVelocity(const double* pX, const double t) {
		return tSpaceVector({
				A * std::sin(pX[2]) + C * std::cos(pX[1]),
				B * std::sin(pX[0]) + A * std::cos(pX[2]),
				C * std::sin(pX[1]) + B * std::cos(pX[0])
		});
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		tSpaceMatrix velocityGradients = tSpaceMatrix::Zero();
		velocityGradients(0,0) = 0.0;                  velocityGradients(0,1) = C * -std::sin(pX[1]); velocityGradients(0,2) = A * std::cos(pX[2]);
		velocityGradients(1,0) = B * std::cos(pX[0]);  velocityGradients(1,1) = 0.0;                  velocityGradients(1,2) = A * -std::sin(pX[2]);
		velocityGradients(2,0) = B * -std::sin(pX[0]); velocityGradients(2,1) = C * std::cos(pX[1]);  velocityGradients(2,2) = 0.0;
		return velocityGradients;
	};
	
	static tSpaceVector getAcceleration(const double* pX, const double t) {
		return tSpaceVector::Zero();
	};
};

}

#endif
