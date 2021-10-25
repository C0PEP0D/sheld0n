#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_7O0_J21_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_7O0_J21_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_20o0__surftimeconst_7o0/j21/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs20O0Surftimeconst7O0J21GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs20O0Surftimeconst7O0J21GroupMember<TypeMemberStep>;
};

}

#endif
