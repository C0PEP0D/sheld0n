#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_7O0__SURFTIMECONST_1O0_J02_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_7O0__SURFTIMECONST_1O0_J02_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/jac/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostSurferUs7O0Surftimeconst1O0J02GroupMemberPassiveJacParameters {
    std::string name = "j";
    // Component index of the flow velocity gradients to extract: 0:x, 1:y, 2:z
    std::size_t i = 0;
    std::size_t j = 2;
};

}

#endif
