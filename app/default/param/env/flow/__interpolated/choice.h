#ifndef C0P_PARAM_FLOW_INTERPOLATED_CHOICE_H
#define C0P_PARAM_FLOW_INTERPOLATED_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/interpolated/unstationary/core.h"
#include "param/env/flow/interpolated/unstationary/parameters.h"
namespace c0p {
    using FlowInterpolated = FlowInterpolatedUnstationary<FlowInterpolatedUnstationaryParameters>;
}

#endif
