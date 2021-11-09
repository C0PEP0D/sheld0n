#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PX_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PX_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_1o5/px/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs1O5Step>
    using PostRiserUs1O5PxGroup = PostPostGroupAll<PostRiserUs1O5PxGroupAllParameters, TypeRiserUs1O5Step>;
}

#endif