#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O0_PY_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O0_PY_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/riser__us_1o0/py/group/_member/choice.h"

namespace c0p {

struct PostRiserUs1O0PyGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostRiserUs1O0PyGroupMember<TypeMemberStep>;
};

}

#endif
