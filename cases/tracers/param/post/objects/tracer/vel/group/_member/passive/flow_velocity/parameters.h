#ifndef C0P_PARAM_POST_OBJECTS_TRACER_VEL_GROUP_MEMBER_PASSIVE_FLOW_VELOCITY_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACER_VEL_GROUP_MEMBER_PASSIVE_FLOW_VELOCITY_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/flow_velocity/prop.h"

namespace c0p {

// Flow velocity post processing
struct PostTracerVelGroupMemberPassiveFlowVelocityParameters {
    std::string name = "u";
};

}

#endif
