#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_6O0_J20_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_6O0_J20_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_0o5__surftimeconst_6o0/j20/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs0O5Surftimeconst6O0J20GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs0O5Surftimeconst6O0J20GroupMember<TypeMemberStep>;
};

}

#endif
