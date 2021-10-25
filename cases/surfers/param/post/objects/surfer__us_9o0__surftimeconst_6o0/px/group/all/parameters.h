#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_6O0_PX_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_6O0_PX_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_9o0__surftimeconst_6o0/px/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs9O0Surftimeconst6O0PxGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs9O0Surftimeconst6O0PxGroupMember<TypeMemberStep>;
};

}

#endif
