#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_7O0_J11_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_7O0_J11_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/jac/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostSurferUs4O0Surftimeconst7O0J11GroupMemberPassiveJacParameters {
    std::string name = "j";
    // Component index of the flow velocity gradients to extract: 0:x, 1:y, 2:z
    std::size_t i = 1;
    std::size_t j = 1;
};

}

#endif
