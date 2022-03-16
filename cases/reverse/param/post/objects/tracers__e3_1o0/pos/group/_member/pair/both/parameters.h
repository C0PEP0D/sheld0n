#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_1O0_POS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_1O0_POS_GROUP_MEMBER_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/pair/both/prop.h"

// post member choice
#include "param/post/objects/tracers__e3_1o0/pos/group/_member/pair/both/_a/choice.h"
#include "param/post/objects/tracers__e3_1o0/pos/group/_member/pair/both/_b/choice.h"

namespace c0p {

// Pair post processing parameters
struct PostTracersE31O0PosGroupMemberPairBothParameters {
    // Specify the post processing to apply to pair members.
    // This parameter should not be changed by the user.
    template<typename TypeAStep>
    using TypePostPostA = PostTracersE31O0PosGroupMemberPairBothA<TypeAStep>;
    template<typename TypeBStep>
    using TypePostPostB = PostTracersE31O0PosGroupMemberPairBothB<TypeBStep>;
};

}

#endif
