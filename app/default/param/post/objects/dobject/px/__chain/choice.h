#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PX_CHAIN_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PX_CHAIN_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/chain/position/core.h"
#include "param/post/objects/dobject/px/chain/position/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using PostDobjectPxChain = PostPostChainPosition<PostDobjectPxChainPositionParameters, TypeDobjectStep>;
}

#endif
