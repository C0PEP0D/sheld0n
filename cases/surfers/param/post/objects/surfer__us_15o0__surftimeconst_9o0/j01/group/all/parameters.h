#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_15O0__SURFTIMECONST_9O0_J01_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_15O0__SURFTIMECONST_9O0_J01_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_15o0__surftimeconst_9o0/j01/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs15O0Surftimeconst9O0J01GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs15O0Surftimeconst9O0J01GroupMember<TypeMemberStep>;
};

}

#endif
