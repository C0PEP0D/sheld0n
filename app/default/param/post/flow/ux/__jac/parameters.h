#ifndef C0P_PARAM_POST_FLOW_UX_JAC_PARAMETERS_H
#define C0P_PARAM_POST_FLOW_UX_JAC_PARAMETERS_H
#pragma once

// app include
#include "core/post/flow/post/jac/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostFlowUxJacParameters {
    std::string name = "j";
    // Component index of the flow velocity gradients to extract: 0:x, 1:y, 2:z
    std::size_t i = 0;
    std::size_t j = 0;
};

}

#endif
