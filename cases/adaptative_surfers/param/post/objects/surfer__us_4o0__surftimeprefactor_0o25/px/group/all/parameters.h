#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_0O25_PX_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_0O25_PX_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o25/px/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs4O0Surftimeprefactor0O25PxGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs4O0Surftimeprefactor0O25PxGroupMember<TypeMemberStep>;
};

}

#endif
