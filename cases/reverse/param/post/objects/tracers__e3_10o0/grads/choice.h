#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_GRADS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_GRADS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/tracers__e3_10o0/grads/group/choice.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE310O0Grads = PostTracersE310O0GradsGroup<TypeObjectStep>;
}

#endif
