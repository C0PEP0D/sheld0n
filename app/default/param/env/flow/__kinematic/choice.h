#ifndef C0P_PARAM_FLOW_KINEMATIC_CHOICE_H
#define C0P_PARAM_FLOW_KINEMATIC_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/kinematic/simple/core.h"
#include "param/env/flow/kinematic/simple/parameters.h"
namespace c0p {
    using FlowKinematic = BaseFlowKinematicSimple<FlowKinematicSimpleParameters>;
}

#endif
