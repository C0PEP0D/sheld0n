#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_5O0_J02_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_5O0_J02_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_5o0/j02/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs5O0Step>
    using PostRiserUs5O0J02Group = PostPostGroupAll<PostRiserUs5O0J02GroupAllParameters, TypeRiserUs5O0Step>;
}

#endif