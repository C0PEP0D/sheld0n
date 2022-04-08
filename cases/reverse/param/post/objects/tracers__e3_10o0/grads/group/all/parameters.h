#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_GRADS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_GRADS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/tracers__e3_10o0/grads/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostTracersE310O0GradsGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostTracersE310O0GradsGroupMember<TypeMemberStep>;
};

}

#endif
