#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_3O0__SURFTIMECONST_6O0_J10_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_3O0__SURFTIMECONST_6O0_J10_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_3o0__surftimeconst_6o0/j10/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs3O0Surftimeconst6O0J10GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs3O0Surftimeconst6O0J10GroupMember<TypeMemberStep>;
};

}

#endif
