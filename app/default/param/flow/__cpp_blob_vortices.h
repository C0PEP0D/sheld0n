#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

#include "pl0f/blob_vortex.h"
#include "param/parameters.h"

namespace c0p {

struct Flow {

	inline static const tSpaceVector meanVelocity = tSpaceVector::Zero();

	using BlobVortexFlow = pl0f::BlobVortexFlow<DIM, tSpaceVector, tSpaceMatrix, tView>;
	inline static BlobVortexFlow flow = BlobVortexFlow(meanVelocity);

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
