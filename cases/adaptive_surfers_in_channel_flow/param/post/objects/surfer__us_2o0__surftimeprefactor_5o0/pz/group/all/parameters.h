#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_5O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_5O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_5o0/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs2O0Surftimeprefactor5O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs2O0Surftimeprefactor5O0PzGroupMember<TypeMemberStep>;
};

}

#endif