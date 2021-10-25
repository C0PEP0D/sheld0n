#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/tracers/pz/group/_member/choice.h"

namespace c0p {

struct PostTracersPzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostTracersPzGroupMember<TypeMemberStep>;
};

}

#endif
