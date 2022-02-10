#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_4O5_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_4O5_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_4o5/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs0O1Surftimeprefactor4O5PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs0O1Surftimeprefactor4O5PzGroupMember<TypeMemberStep>;
};

}

#endif
