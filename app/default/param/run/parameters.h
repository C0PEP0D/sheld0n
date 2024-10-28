#ifndef C0P_PARAM_RUN_PARAPETERS_H
#define C0P_PARAM_RUN_PARAMETERS_H
#pragma once

#include "core/run/prop.h"

namespace c0p {

// Run simulation parameters
struct RunParameters {
    // Fixed time step of the simulation.
    // Should be greater than zero.
    static constexpr double Dt = 1.0/128.0;
    // Number of time steps of the simulation.
    // Should be greater than zero.
    static const unsigned int NTime = std::round(10.0 / Dt);
    // Number of time steps that will be saved.
    // Currently, post processing will only be
    // possible to be performed on saved time steps.
    // Should be greater than zero.
    static const unsigned int NSave = NTime;
    // If enbaled all static objects are saved
    // in the same file. May lead to slightly
    // faster simulations.
    static const bool IsMergingStatic = false;
};

}

#endif
