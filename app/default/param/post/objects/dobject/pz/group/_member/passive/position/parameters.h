#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PZ_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PZ_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/position/prop.h"

namespace c0p {

struct PostDobjectPzGroupMemberPassivePositionParameters {
    std::string name = "pos";
    std::size_t i = 2;
};

}

#endif
