#ifndef C0P_PARAM_RUN_PARAPETERS_H
#define C0P_PARAM_RUN_PARAMETERS_H
#pragma once

#include "core/run/prop.h"

namespace c0p {

// Run simulation parameters
struct RunParameters {
    // Fixed time step of the simulation.
    // Should be greater than zero.
    double dt = 0.0065;
    // Number of time steps of the simulation.
    // Should be greater than zero.
    std::size_t nt = std::round(25.9935 / dt);
    // Number of time steps that will be saved.
    // Currently, post processing will only be
    // possible to be performed on saved time steps.
    // Should be greater than zero.
    std::size_t nsave = nt;
    // If enbaled all static objects are saved
    // in the same file. May lead to slightly
    // faster simulations.
    bool saveStaticMerge = false;
};

}

#endif
