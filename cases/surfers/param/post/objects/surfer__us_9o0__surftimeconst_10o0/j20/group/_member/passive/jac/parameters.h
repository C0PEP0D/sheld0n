#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_10O0_J20_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_10O0_J20_GROUP_MEMBER_PASSIVE_JAC_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/passive/jac/prop.h"

namespace c0p {

// Flow velocity gradients post processing
struct PostSurferUs9O0Surftimeconst10O0J20GroupMemberPassiveJacParameters {
    std::string name = "j";
    // Component index of the flow velocity gradients to extract: 0:x, 1:y, 2:z
    std::size_t i = 2;
    std::size_t j = 0;
};

}

#endif
