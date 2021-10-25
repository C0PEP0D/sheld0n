#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_1O75_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_1O75_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_1o75/pz/group/_member/choice.h"

namespace c0p {

struct PostSurferUs4O0Surftimeprefactor1O75PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs4O0Surftimeprefactor1O75PzGroupMember<TypeMemberStep>;
};

}

#endif
