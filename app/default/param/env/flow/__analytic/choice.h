#ifndef C0P_PARAM_FLOW_ANALYTIC_CHOICE_H
#define C0P_PARAM_FLOW_ANALYTIC_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/analytic/taylor_green_vortex/core.h"
#include "param/env/flow/analytic/taylor_green_vortex/parameters.h"
namespace c0p {
    using FlowAnalytic = BaseFlowAnalyticTaylorGreenVortex<FlowAnalyticTaylorGreenVortexParameters>;
}

#endif
