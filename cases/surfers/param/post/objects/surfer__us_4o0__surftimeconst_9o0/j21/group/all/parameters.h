#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_9O0_J21_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_9O0_J21_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_4o0__surftimeconst_9o0/j21/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs4O0Surftimeconst9O0J21GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs4O0Surftimeconst9O0J21GroupMember<TypeMemberStep>;
};

}

#endif
