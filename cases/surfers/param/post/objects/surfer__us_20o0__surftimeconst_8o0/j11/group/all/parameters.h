#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_8O0_J11_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_8O0_J11_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_20o0__surftimeconst_8o0/j11/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs20O0Surftimeconst8O0J11GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs20O0Surftimeconst8O0J11GroupMember<TypeMemberStep>;
};

}

#endif
