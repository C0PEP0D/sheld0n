#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_PY_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_PY_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/tracers/py/group/_member/choice.h"

namespace c0p {

struct PostTracersPyGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostTracersPyGroupMember<TypeMemberStep>;
};

}

#endif
