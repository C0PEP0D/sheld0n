#ifndef C0P_PARAM_FLOW_TAYLOR_GREEN_VORTEX_CHOICE_H
#define C0P_PARAM_FLOW_TAYLOR_GREEN_VORTEX_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/taylor_green_vortex/simple/core.h"
#include "param/env/flow/taylor_green_vortex/simple/parameters.h"
namespace c0p {
    using FlowTaylorGreenVortex = FlowTaylorGreenVortexSimple<FlowTaylorGreenVortexSimpleParameters>;
}

#endif
