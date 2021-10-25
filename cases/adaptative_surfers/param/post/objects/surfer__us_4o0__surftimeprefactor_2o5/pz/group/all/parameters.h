#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O5_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O5_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o5/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs4O0Surftimeprefactor2O5PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs4O0Surftimeprefactor2O5PzGroupMember<TypeMemberStep>;
};

}

#endif
