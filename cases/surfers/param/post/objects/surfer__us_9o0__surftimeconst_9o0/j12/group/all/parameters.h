#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_9O0_J12_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_9O0_J12_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_9o0__surftimeconst_9o0/j12/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs9O0Surftimeconst9O0J12GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs9O0Surftimeconst9O0J12GroupMember<TypeMemberStep>;
};

}

#endif
