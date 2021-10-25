#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_6O0__SURFTIMECONST_10O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_6O0__SURFTIMECONST_10O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_6o0__surftimeconst_10o0/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs6O0Surftimeconst10O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs6O0Surftimeconst10O0PzGroupMember<TypeMemberStep>;
};

}

#endif
