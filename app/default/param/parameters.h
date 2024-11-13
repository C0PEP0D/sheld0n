#ifndef C0P_PARAM_PARAMETERS_H
#define C0P_PARAM_PARAMETERS_H
#pragma once

#include "core/prop.h"

namespace c0p {

// define if the simulation is in 2D or 3D 
constexpr unsigned int DIM = 2;
// definition of a SpaceVector and a SpaceMatrix,
// this should not be edited
using tSpaceVector = tVector<DIM>;
using tSpaceMatrix = tMatrix<DIM, DIM>;

// main simulation parameters
// the users can add whatever parameters they judge suitable,
// these parameters are accessible from the other parameter files
struct EnvParameters {
    // optional characteristic group size. 
    // should be greater than zero.
    constexpr static const double cGroupSize = 16;
    // optional characteristic scales used to parameterize equations.
    constexpr static const double cLength = M_PI;
    constexpr static const double cTime = M_PI;
    constexpr static const double cVelocity = cLength / cTime;
    // seed used for random generation
    constexpr static const unsigned int randomSeed = 0;
    EnvParameters() {
        rand0m::seed(randomSeed); // comment this line to set a random seed
    }
};

}

#endif
