#ifndef C0P_CORE_ENV_FLOW_ANALYTIC_TAYLOR_GREEN_VORTEX_CORE_H
#define C0P_CORE_ENV_FLOW_ANALYTIC_TAYLOR_GREEN_VORTEX_CORE_H
#pragma once

// Std includes
// Lib includes
#include "fl0w/analytic/taylor_green_vortex.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/analytic/taylor_green_vortex/prop.h"

namespace c0p {

template<typename tParameters>
struct FlowAnalyticTaylorGreenVortex : public fl0w::analytic::FlowTaylorGreenVortex<tSpaceVector, tSpaceMatrix, tView> {
};

}

#endif
