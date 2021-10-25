#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_15O0__SURFTIMECONST_8O0_J12_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_15O0__SURFTIMECONST_8O0_J12_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/jac/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostSurferUs15O0Surftimeconst8O0J12GroupMemberPassiveJacParameters {
    std::string name = "j";
    // Component index of the flow velocity gradients to extract: 0:x, 1:y, 2:z
    std::size_t i = 1;
    std::size_t j = 2;
};

}

#endif
