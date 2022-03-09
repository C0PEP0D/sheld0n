#ifndef C0P_PARAM_POST_OBJECTS_MOBJECT_POS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_MOBJECT_POS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/mobject/pos/manager/choice.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostMobjectPos = PostMobjectPosManager<TypeObjectStep>;
}

#endif
