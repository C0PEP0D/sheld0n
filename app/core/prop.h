#ifndef C0P_CORE_ENV_PROP_H
#define C0P_CORE_ENV_PROP_H
#pragma once

// thirdparties includes
#include <Eigen/Dense>
// std
#include <random>
// lib includes
#include "s0s/runge_kutta_fehlberg.h"
// app includes
#include "param/parameters.h"

namespace c0p {

// Type Declarations

using tScalar = double;
// Algebra
template<const int ...Args>
using tMatrix = Eigen::Matrix<tScalar, Args...>;
template<const int Size>
using tVector = tMatrix<Size, 1>;
template<typename ...Args>
using tView = Eigen::Map<Args...>;
using tStateVectorDynamic = tVector<Eigen::Dynamic>;
// Solver
using tSolver = s0s::SolverRungeKuttaFehlberg<tStateVectorDynamic, tView>;

namespace rand0m {
	std::random_device device;
	std::default_random_engine engine(device());
	// distribution
	std::normal_distribution<> standardNormalDistribution(0.0, 1.0);
	std::uniform_real_distribution<> uniformRealDistribution(-1.0, 1.0);

	void seed(unsigned int p_seed) {
		engine.seed(p_seed);
		std::srand(p_seed);
	}
}

}

#endif
