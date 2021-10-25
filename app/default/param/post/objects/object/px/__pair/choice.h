#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_PX_PAIR_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_PX_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/pair/both/core.h"
#include "param/post/objects/object/px/pair/both/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostObjectPxPair = PostPostPairBoth<PostObjectPxPairBothParameters, TypeObjectStep>;
}

#endif
