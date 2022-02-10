#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O1_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O1_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o1/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs0O5Surftimeconst0O1PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs0O5Surftimeconst0O1PzGroupMember<TypeMemberStep>;
};

}

#endif
