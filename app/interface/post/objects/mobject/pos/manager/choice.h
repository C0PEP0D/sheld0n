#ifndef C0P_PARAM_POST_OBJECTS_MOBJECT_POS_MANAGER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_MOBJECT_POS_MANAGER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/manager/all/core.h"
#include "param/post/objects/mobject/pos/manager/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostMobjectPosManager = PostPostManagerAll<PostMobjectPosManagerAllParameters, TypeObjectStep>;
}

#endif
