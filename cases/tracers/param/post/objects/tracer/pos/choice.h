#ifndef C0P_PARAM_POST_OBJECTS_TRACER_POS_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACER_POS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/tracer/pos/group/choice.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracerPos = PostTracerPosGroup<TypeObjectStep>;
}

#endif
