#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_2O5_PX_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_2O5_PX_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_2o5/px/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs8O0Surftimeprefactor2O5PxGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs8O0Surftimeprefactor2O5PxGroupMember<TypeMemberStep>;
};

}

#endif
