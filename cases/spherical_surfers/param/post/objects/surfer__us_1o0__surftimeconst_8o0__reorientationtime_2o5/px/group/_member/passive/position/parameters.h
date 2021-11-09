#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0__REORIENTATIONTIME_2O5_PX_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0__REORIENTATIONTIME_2O5_PX_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/position/prop.h"

namespace c0p {

// Position post processing parameters
struct PostSurferUs1O0Surftimeconst8O0Reorientationtime2O5PxGroupMemberPassivePositionParameters {
    std::string name = "pos";
    // Component index of the position to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
