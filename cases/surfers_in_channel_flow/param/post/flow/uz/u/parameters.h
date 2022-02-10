#ifndef C0P_PARAM_POST_FLOW_UZ_U_PARAMETERS_H
#define C0P_PARAM_POST_FLOW_UZ_U_PARAMETERS_H
#pragma once

// app include
#include "core/post/flow/post/u/prop.h"

namespace c0p {

// Flow velocity post processing
struct PostFlowUzUParameters {
    std::string name = "u";
    // Component index of the flow velocity to extract. 0:x, 1:y, 2:z
    std::size_t i = 2;
};

}

#endif
