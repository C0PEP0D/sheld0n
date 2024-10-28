#ifndef C0P_PARAM_FLOW_ANALYTIC_UNIFORM_PARAMETERS_H
#define C0P_PARAM_FLOW_ANALYTIC_UNIFORM_PARAMETERS_H
#pragma once

#include "core/env/flow/analytic/uniform/prop.h"

namespace c0p {

struct FlowUniformParameters {
    inline static const std::array<double, DIM> Velocity = {0.0, 0.0};
};

}

#endif
