#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O01_GRADS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O01_GRADS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/pair/both/prop.h"

// post member choice
#include "param/post/objects/tracers__e3_0o01/grads/group/_member/pair/both/_a/choice.h"
#include "param/post/objects/tracers__e3_0o01/grads/group/_member/pair/both/_b/choice.h"

namespace c0p {

// Pair post processing parameters
struct PostTracersE30O01GradsGroupMemberPairBothParameters {
    // Specify the post processing to apply to pair members.
    // This parameter should not be changed by the user.
    template<typename TypeAStep>
    using TypePostPostA = PostTracersE30O01GradsGroupMemberPairBothA<TypeAStep>;
    template<typename TypeBStep>
    using TypePostPostB = PostTracersE30O01GradsGroupMemberPairBothB<TypeBStep>;
};

}

#endif
