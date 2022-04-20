#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O0_POS_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O0_POS_GROUP_MEMBER_PASSIVE_POSITION_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/position/prop.h"

namespace c0p {

// Position post processing parameters
struct PostSurferUs0O1Surftimeconst0O0PosGroupMemberPassivePositionParameters {
    std::string name = "pos";
    // Component index of the position to extract. 0:x, 1:y, 2:z
    std::size_t i = 0;
};

}

#endif
