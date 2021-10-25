#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O5__SURFTIMECONST_9O0_J00_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O5__SURFTIMECONST_9O0_J00_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_1o5__surftimeconst_9o0/j00/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs1O5Surftimeconst9O0J00GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs1O5Surftimeconst9O0J00GroupMember<TypeMemberStep>;
};

}

#endif
