#ifndef C0P_PARAM_FLOW_REVERSE_CHOICE_H
#define C0P_PARAM_FLOW_REVERSE_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/reverse/core.h"
#include "param/env/flow/reverse/parameters.h"
// flow choice
#include "param/env/flow/reverse/_flow/choice.h"
namespace c0p {
    using FlowReverse = BaseFlowReverse<FlowReverseParameters, FlowReverseFlow>;
}

#endif
