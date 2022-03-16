#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E2_1O0_POS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E2_1O0_POS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/tracers__e2_1o0/pos/group/choice.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE21O0Pos = PostTracersE21O0PosGroup<TypeObjectStep>;
}

#endif
