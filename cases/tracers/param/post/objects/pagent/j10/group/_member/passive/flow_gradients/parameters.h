#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_J10_GROUP_MEMBER_PASSIVE_FLOW_GRADIENTS_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_J10_GROUP_MEMBER_PASSIVE_FLOW_GRADIENTS_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/flow_gradients/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostPagentJ10GroupMemberPassiveFlowGradientsParameters {
    std::string name = "j";
    // Component index of the flow velocity gradients to extract: 0:x, 1:y, 2:z
    std::size_t i = 1;
    std::size_t j = 0;
};

}

#endif