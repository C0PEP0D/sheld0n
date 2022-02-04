#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_UX_GROUP_MEMBER_PASSIVE_FLOW_VELOCITY_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_UX_GROUP_MEMBER_PASSIVE_FLOW_VELOCITY_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/flow_velocity/prop.h"

namespace c0p {

// Flow velocity post processing
struct PostPagentUxGroupMemberPassiveFlowVelocityParameters {
    std::string name = "u";
    // Component index of the flow velocity to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
