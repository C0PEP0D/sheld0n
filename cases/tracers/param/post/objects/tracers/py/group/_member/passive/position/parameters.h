#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_PY_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_PY_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/position/prop.h"

namespace c0p {

struct PostTracersPyGroupMemberPassivePositionParameters {
    std::string name = "pos";
    std::size_t i = 1;
};

}

#endif
