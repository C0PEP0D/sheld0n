#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

#include "pl0f/point_vortex.h"
#include "param/parameters.h"

namespace c0p {

struct Flow {

	inline static const double step = std::pow(2, -10); // basically the spatial resolution of the flow, should be the inverse of the density of points
	// periodicity
	inline static const tSpaceVector periodCenter = EnvParameters::cDomainCenter;
	inline static const tSpaceVector periodSize = EnvParameters::cDomainSize;
	inline static const std::array<bool, DIM> isAxisPeriodic = EnvParameters::cDomainIsAxisPeriodic;

	using PointVortexFlow = pl0f::PointVortexFlow<DIM, tSpaceVector, tSpaceMatrix, tView>;
	inline static PointVortexFlow flow = PointVortexFlow(step, periodCenter, periodSize, isAxisPeriodic);

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
	
	static void prepareVelocity(const double* pX, const double t) {
	}
	
	static void prepareVelocityGradients(const double* pX, const double t) {
	}

};

}

#endif
