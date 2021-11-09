#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O0_J01_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O0_J01_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_2o0/j01/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs2O0Step>
    using PostRiserUs2O0J01Group = PostPostGroupAll<PostRiserUs2O0J01GroupAllParameters, TypeRiserUs2O0Step>;
}

#endif
