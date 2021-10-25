#ifndef C0P_PARAM_FLOW_KINEMATIC_SIMPLE_PARAMETERS_H
#define C0P_PARAM_FLOW_KINEMATIC_SIMPLE_PARAMETERS_H
#pragma once

#include "core/env/flow/kinematic/simple/prop.h"

namespace c0p {

struct FlowKinematicSimpleParameters {
    // Flow
    // // Numerical
    std::size_t seed = 0; // Random seed
    std::size_t nk = 100; // Number of modes
    // // "Numerical"
    double k0 = 1.6; // Kolmogorov constant
    double nu = 1e-6;
    double eps = 1e-5;
    double l = 1e-2;
    double lambda = 0.4; // Pulsation generator parameter (should be 0.4, or 0.0 in case of a stationary flow)
};

}

#endif
