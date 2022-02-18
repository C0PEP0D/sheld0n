#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O9_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O9_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o9/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs0O1Surftimeconst0O9PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs0O1Surftimeconst0O9PzGroupMember<TypeMemberStep>;
};

}

#endif