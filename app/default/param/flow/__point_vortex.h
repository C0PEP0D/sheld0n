#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

#include "pl0f/flow.h"

namespace c0p {

struct Flow {

	using PointVortexFlow = pl0f::PointVortexFlow<Dim, tSpaceVector, tSpaceMatrix, tView>
	using tVorticesEquation = _Vortices; // name of the objects

	inline static PointVortexFlow flow;

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

	static void prepare(const double* pState, const unsigned int stateSize, const double t) {
		const tView<const tStateVectorDynamic> state(
			Solutions::tSolutionStatic::tEquation::tVariable::template cState<typename tVorticesEquation::tVariable>(
				pState
			),
			tVorticesEquation::tVariable::Size
		);
		// TODO: give in state -> with both position and vorticity (to match current structure)
		flow.prepare(const double* pPosition, const double* pVorticity, tVorticesEquation::tVariable::GroupSize);
	}
	
	static void prepareVelocity(const double* pX, const double t) {
	}
	
	static void prepareVelocityGradients(const double* pX, const double t) {
	}

};

}

#endif
