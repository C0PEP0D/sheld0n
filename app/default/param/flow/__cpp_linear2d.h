#ifndef C0P_PARAM_FLOW_PARAMETERS_H
#define C0P_PARAM_FLOW_PARAMETERS_H
#pragma once

// std includes
#include <array>

namespace c0p {

struct Flow {

	static constexpr std::array<double, DIM> Velocity0 = {
		1.0, 
		0.0
	};
	static constexpr std::array<double, DIM * DIM> Gradient = {
		1.0,  1.0,
		1.0, -1.0
	};
	static constexpr std::array<double, DIM> Acceleration = {
		0.0, 
		0.0
	};

	static void init() {
		// nothing to do
	}

	// get

	static tSpaceVector getVelocity(const double* pX, const double t) {
		// parameters
		const tView<const tSpaceVector> u0(Velocity0.data());
		const tView<const tSpaceMatrix> grad(Gradient.data());
		const tView<const tSpaceVector> a(Acceleration.data());
		// input
		const tView<const tSpaceVector> x(pX);
		// output
		return u0 + grad * x + a * t;
	};

	static tSpaceMatrix getVelocityGradients(const double* pX, const double t) {
		return tView<const tSpaceMatrix>(Gradient.data());
	};
	

	// prepare

	template<typename tEquationStatic, typename tEquationFlow>
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
