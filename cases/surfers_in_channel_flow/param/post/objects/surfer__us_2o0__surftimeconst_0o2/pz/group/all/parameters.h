#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O2_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O2_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o2/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs2O0Surftimeconst0O2PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs2O0Surftimeconst0O2PzGroupMember<TypeMemberStep>;
};

}

#endif
