#ifndef C0P_PARAM_PARAMETERS_H
#define C0P_PARAM_PARAMETERS_H
#pragma once

#include "core/prop.h"

namespace c0p {

// Main simulation parameters
// The users can add whatever parameters they judge suitable.
// This parameters are accessible from the other parameter files.
struct EnvParameters {
    // Characteristic group size. 
    // Should be greater than zero.
    constexpr static const double cGroupSize = 128;
    // Characteristic scales used to parametrize objects.
    // Currently corresponds to the Kolmogorov scales of the JHTDB flow.
    constexpr static const double cLength = 0.00280;
    constexpr static const double cTime = 0.0424;
    constexpr static const double cVelocity = cLength / cTime;
    // Characteristic angle
    constexpr static const double cAngle = M_PI;

    // Seed used for random generation
    constexpr static const unsigned int randomSeed = 0;
    EnvParameters() {
        rand0m::seed(randomSeed);
    }
};

}

#endif
