#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O5__SURFTIMECONST_1O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O5__SURFTIMECONST_1O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_2o5__surftimeconst_1o0/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs2O5Surftimeconst1O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs2O5Surftimeconst1O0PzGroupMember<TypeMemberStep>;
};

}

#endif
