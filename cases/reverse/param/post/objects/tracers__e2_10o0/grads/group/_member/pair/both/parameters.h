#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E2_10O0_GRADS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E2_10O0_GRADS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/pair/both/prop.h"

// post member choice
#include "param/post/objects/tracers__e2_10o0/grads/group/_member/pair/both/_a/choice.h"
#include "param/post/objects/tracers__e2_10o0/grads/group/_member/pair/both/_b/choice.h"

namespace c0p {

// Pair post processing parameters
struct PostTracersE210O0GradsGroupMemberPairBothParameters {
    // Specify the post processing to apply to pair members.
    // This parameter should not be changed by the user.
    template<typename TypeAStep>
    using TypePostPostA = PostTracersE210O0GradsGroupMemberPairBothA<TypeAStep>;
    template<typename TypeBStep>
    using TypePostPostB = PostTracersE210O0GradsGroupMemberPairBothB<TypeBStep>;
};

}

#endif
