#ifndef C0P_PARAM_POST_FLOW_GRAD_GRADIENTS_PARAMETERS_H
#define C0P_PARAM_POST_FLOW_GRAD_GRADIENTS_PARAMETERS_H
#pragma once

// app include
#include "core/post/flow/post/gradients/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostFlowGradGradientsParameters {
    std::string name = "j";
};

}

#endif
