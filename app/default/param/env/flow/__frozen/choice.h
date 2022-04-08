#ifndef C0P_PARAM_FLOW_FROZEN_CHOICE_H
#define C0P_PARAM_FLOW_FROZEN_CHOICE_H
#pragma once

// choose your flow
#include "core/env/flow/frozen/core.h"
#include "param/env/flow/frozen/parameters.h"
// flow choice
#include "param/env/flow/frozen/_flow/choice.h"
namespace c0p {
    using FlowFrozen = BaseFlowFrozen<FlowFrozenParameters, FlowFrozenFlow>;
}

#endif
