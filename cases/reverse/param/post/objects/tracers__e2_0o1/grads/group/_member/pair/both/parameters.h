#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E2_0O1_GRADS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E2_0O1_GRADS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/pair/both/prop.h"

// post member choice
#include "param/post/objects/tracers__e2_0o1/grads/group/_member/pair/both/_a/choice.h"
#include "param/post/objects/tracers__e2_0o1/grads/group/_member/pair/both/_b/choice.h"

namespace c0p {

// Pair post processing parameters
struct PostTracersE20O1GradsGroupMemberPairBothParameters {
    // Specify the post processing to apply to pair members.
    // This parameter should not be changed by the user.
    template<typename TypeAStep>
    using TypePostPostA = PostTracersE20O1GradsGroupMemberPairBothA<TypeAStep>;
    template<typename TypeBStep>
    using TypePostPostB = PostTracersE20O1GradsGroupMemberPairBothB<TypeBStep>;
};

}

#endif
