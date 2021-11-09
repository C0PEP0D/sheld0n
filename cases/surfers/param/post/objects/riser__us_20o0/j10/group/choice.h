#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_20O0_J10_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_20O0_J10_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_20o0/j10/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs20O0Step>
    using PostRiserUs20O0J10Group = PostPostGroupAll<PostRiserUs20O0J10GroupAllParameters, TypeRiserUs20O0Step>;
}

#endif
