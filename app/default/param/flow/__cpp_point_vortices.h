#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

#include "pl0f/point_vortex.h"
// #include "core/solutions/core.h"
// #include "param/solutions/parameters.h"

namespace c0p {

struct Flow {

	inline static const double dx = std::pow(2, -4); // basically the spatial resolution of the flow, should be the inverse of the density of points
	inline static const tSpaceVector meanVelocity = tSpaceVector::Zero();

	using PointVortexFlow = pl0f::PointVortexFlow<DIM, tSpaceVector, tSpaceMatrix, tView>;
	inline static PointVortexFlow flow = PointVortexFlow(dx, meanVelocity);

	// using tVorticesEquation = _PassiveParticles; // name of the vortices

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		return flow.getVelocity(pX);
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		return flow.getVelocityGradients(pX);
	};

	// prepare

	static void prepare(const double* pState, const unsigned int vortexNumber) { // called by point vortices
		flow.prepare(pState, vortexNumber);
	}

	static void prepare(const double t) {
	}
	
	static void prepareVelocity(const double* pX, const double t) {
	}
	
	static void prepareVelocityGradients(const double* pX, const double t) {
	}

};

}

#endif
