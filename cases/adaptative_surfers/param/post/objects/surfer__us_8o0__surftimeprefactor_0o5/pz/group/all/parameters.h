#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_0O5_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_0O5_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o5/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs8O0Surftimeprefactor0O5PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs8O0Surftimeprefactor0O5PzGroupMember<TypeMemberStep>;
};

}

#endif
