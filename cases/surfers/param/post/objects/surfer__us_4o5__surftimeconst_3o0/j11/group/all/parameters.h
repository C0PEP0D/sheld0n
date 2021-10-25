#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O5__SURFTIMECONST_3O0_J11_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O5__SURFTIMECONST_3O0_J11_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_4o5__surftimeconst_3o0/j11/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs4O5Surftimeconst3O0J11GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs4O5Surftimeconst3O0J11GroupMember<TypeMemberStep>;
};

}

#endif
