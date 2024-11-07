#ifndef C0P_PARAM_FLOW_ANALYTIC_PARAMETERS_H
#define C0P_PARAM_FLOW_ANALYTIC_PARAMETERS_H
#pragma once

// std includes
#include <array>

namespace c0p {

struct FlowAnalytic {

	static constexpr std::array<double, DIM> u = {1.0, 0.0}; // defined in 2D, use {1.0, 0.0, 0.0} in 3D

	static tSpaceVector getVelocity(const double* pX, const double t) {
		return tView<const tSpaceVector>(u.data());
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		return tSpaceMatrix::Zero();
	};
	
	static tSpaceVector getAcceleration(const double* pX, const double t) {
		return tSpaceVector::Zero();
	};
};

}

#endif
