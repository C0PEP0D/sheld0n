#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_POS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_POS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/dobject/pos/chain/choice.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using PostDobjectPos = PostDobjectPosChain<TypeDobjectStep>;
}

#endif
