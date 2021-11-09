#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_9O0_J20_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_9O0_J20_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_9o0/j20/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs9O0Step>
    using PostRiserUs9O0J20Group = PostPostGroupAll<PostRiserUs9O0J20GroupAllParameters, TypeRiserUs9O0Step>;
}

#endif