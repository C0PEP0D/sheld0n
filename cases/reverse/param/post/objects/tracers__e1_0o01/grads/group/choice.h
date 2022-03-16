#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E1_0O01_GRADS_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E1_0O01_GRADS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/tracers__e1_0o01/grads/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE10O01GradsGroup = PostPostGroupAll<PostTracersE10O01GradsGroupAllParameters, TypeObjectStep>;
}

#endif
