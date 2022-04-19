#ifndef C0P_PARAM_ENV_PARAMETERS_H
#define C0P_PARAM_ENV_PARAMETERS_H
#pragma once

// std includes
#include <ctime>
#include <random>
// app includes
#include "core/env/prop.h"

namespace c0p {

// Main environnement parameters
struct EnvParameters {
    // Seed used for random generation
    static const unsigned int randomSeed = 0;

    EnvParameters() {
        rand0m::seed(randomSeed);
    }
};

}

#endif
