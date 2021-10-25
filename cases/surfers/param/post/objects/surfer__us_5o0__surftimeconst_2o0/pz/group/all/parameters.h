#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_2O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_2O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_5o0__surftimeconst_2o0/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs5O0Surftimeconst2O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs5O0Surftimeconst2O0PzGroupMember<TypeMemberStep>;
};

}

#endif
