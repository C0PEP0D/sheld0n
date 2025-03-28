#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

#include "fl0w/jhtdb.h"

namespace c0p {

struct Flow {

	using FlowJhtdb = fl0w::Jhtdb<tSpaceVector, tSpaceMatrix, tView>;

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		return FlowJhtdb::Isotropic::getVelocity(pX, t);
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		return FlowJhtdb::Isotropic::getVelocityGradients(pX, t);
	};

	// prepare
	
	static void prepareVelocity(const double* pX, const double t) {
		FlowJhtdb::Isotropic::prepareVelocity(pX, t);
	}
	
	static void prepareVelocityGradients(const double* pX, const double t) {
		FlowJhtdb::Isotropic::prepareVelocityGradients(pX, t);
	}

};

}

#endif
