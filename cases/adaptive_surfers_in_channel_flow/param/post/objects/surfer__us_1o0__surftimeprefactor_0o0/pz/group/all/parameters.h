#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_0O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_0O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_0o0/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs1O0Surftimeprefactor0O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs1O0Surftimeprefactor0O0PzGroupMember<TypeMemberStep>;
};

}

#endif
