#ifndef C0P_CORE_ENV_FLOW_ANALYTIC_UNIFORM_CORE_H
#define C0P_CORE_ENV_FLOW_ANALYTIC_UNIFORM_CORE_H
#pragma once

// Std includes
// Lib includes
#include "fl0w/analytic/uniform.h"
// App includes
#include "core/env/prop.h"
#include "core/env/flow/analytic/uniform/prop.h"

namespace c0p {

template<typename tParameters>
struct FlowAnalyticUniform : public fl0w::analytic::FlowUniform<tSpaceVector, tSpaceMatrix, tView, tParameters::Velocity> {
};

}

#endif
