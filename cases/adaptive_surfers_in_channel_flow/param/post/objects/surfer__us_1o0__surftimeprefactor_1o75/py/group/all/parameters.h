#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_1O75_PY_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_1O75_PY_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o75/py/group/_member/choice.h"

namespace c0p {

struct PostSurferUs1O0Surftimeprefactor1O75PyGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs1O0Surftimeprefactor1O75PyGroupMember<TypeMemberStep>;
};

}

#endif
