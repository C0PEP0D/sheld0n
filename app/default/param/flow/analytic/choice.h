#ifndef C0P_PARAM_FLOW_ANALYTIC_CHOICE_H
#define C0P_PARAM_FLOW_ANALYTIC_CHOICE_H
#pragma once

// choose your flow
#include "core/flow/analytic/taylor_green_vortex/core.h"
#include "param/flow/analytic/taylor_green_vortex/parameters.h"
namespace c0p {
    using FlowAnalytic = FlowAnalyticTaylorGreenVortex<FlowAnalyticTaylorGreenVortexParameters>;
}

#endif
