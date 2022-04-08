#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_PAIR_BOTH_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_PAIR_BOTH_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/pair/both/prop.h"

// post member choice
#include "param/post/objects/object/pos/group/_member/pair/both/_a/choice.h"
#include "param/post/objects/object/pos/group/_member/pair/both/_b/choice.h"

namespace c0p {

// Pair post processing parameters
struct PostObjectPosPairBothParameters {
    // Specify the post processing to apply to pair members.
    // This parameter should not be changed by the user.
    template<typename TypeAStep>
    using TypePostPostA = PostObjectPosPairBothA<TypeAStep>;
    template<typename TypeBStep>
    using TypePostPostB = PostObjectPosPairBothB<TypeBStep>;
};

}

#endif
