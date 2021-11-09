#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O0_J12_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O0_J12_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_4o0/j12/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs4O0Step>
    using PostRiserUs4O0J12Group = PostPostGroupAll<PostRiserUs4O0J12GroupAllParameters, TypeRiserUs4O0Step>;
}

#endif
