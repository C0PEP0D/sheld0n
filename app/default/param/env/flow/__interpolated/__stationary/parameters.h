#ifndef C0P_PARAM_FLOW_INTERPOLATION_STATIONARY_PROP_H
#define C0P_PARAM_FLOW_INTERPOLATION_STATIONARY_PROP_H
#pragma once

#include "core/env/flow/interpolated/stationary/prop.h"

namespace c0p {

struct FlowInterpolatedStationaryParameters {
    std::string fileName = "../data/v5300.vtk"; // file name
    std::size_t order = 4; // interpolation order
};

}

#endif
