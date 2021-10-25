#ifndef C0P_PARAM_FLOW_INTERPOLATION_UNSTATIONARY_PROP_H
#define C0P_PARAM_FLOW_INTERPOLATION_UNSTATIONARY_PROP_H
#include <bits/c++config.h>
#pragma once

#include "core/env/flow/interpolated/unstationary/prop.h"

namespace c0p {

struct FlowInterpolatedUnstationaryParameters {
    std::string directory = "../data";
    std::size_t spaceOrder = 4; // interpolation order
    std::size_t timeOrder = 2; // interpolation order
    double dt = 0.001;
};

}

#endif
