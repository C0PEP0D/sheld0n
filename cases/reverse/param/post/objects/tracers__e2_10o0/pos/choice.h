#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E2_10O0_POS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E2_10O0_POS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/tracers__e2_10o0/pos/group/choice.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE210O0Pos = PostTracersE210O0PosGroup<TypeObjectStep>;
}

#endif
