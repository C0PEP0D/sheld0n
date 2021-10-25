#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_1O0_J00_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_1O0_J00_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_5o0__surftimeconst_1o0/j00/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs5O0Surftimeconst1O0J00GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs5O0Surftimeconst1O0J00GroupMember<TypeMemberStep>;
};

}

#endif
