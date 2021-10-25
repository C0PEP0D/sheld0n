#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_1O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_1O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_4o0__surftimeconst_1o0/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs4O0Surftimeconst1O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs4O0Surftimeconst1O0PzGroupMember<TypeMemberStep>;
};

}

#endif
