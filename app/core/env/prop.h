#ifndef C0P_CORE_ENV_ENV_PROP_H
#define C0P_CORE_ENV_ENV_PROP_H
#pragma once

// thirdparties includes
#include <Eigen/Dense>
// std
#include <random>
// lib includes
#include "s0s/runge_kutta_fehlberg.h"

namespace c0p {

// Type Declarations

using TypeScalar = double;
//Algebra
template<const int ...Args>
using TypeMatrix = Eigen::Matrix<TypeScalar, Args...>;
template<const int Size>
using TypeVector = TypeMatrix<Size, 1>;
template<typename ...Args>
using TypeRef = Eigen::Ref<Args...>;
template<typename ...Args>
using TypeView = Eigen::Map<Args...>;
// Container type
template<typename ...Args>
using TypeContainer = std::vector<Args...>;
// Space
constexpr unsigned int DIM = 3; // 2D or 3D
using TypeSpaceVector = TypeVector<DIM>;
using TypeSpaceMatrix = TypeMatrix<DIM, DIM>;
// Solver
using TypeSolver = s0s::SolverRungeKuttaFehlberg<TypeVector<-1>, TypeView>;

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

    TypeSpaceVector getRandomUnitVector() {
    	return TypeSpaceVector({
    		standardNormalDistribution(engine), 
    		standardNormalDistribution(engine), 
    		standardNormalDistribution(engine)
    	}).normalized();
    }
}

}

#endif
