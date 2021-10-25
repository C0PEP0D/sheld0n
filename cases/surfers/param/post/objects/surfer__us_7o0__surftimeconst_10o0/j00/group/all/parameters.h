#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_7O0__SURFTIMECONST_10O0_J00_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_7O0__SURFTIMECONST_10O0_J00_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_7o0__surftimeconst_10o0/j00/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs7O0Surftimeconst10O0J00GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs7O0Surftimeconst10O0J00GroupMember<TypeMemberStep>;
};

}

#endif
