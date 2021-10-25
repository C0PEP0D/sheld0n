#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_15O0_J00_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_15O0_J00_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_15o0/j00/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs15O0Step>
    using PostRiserUs15O0J00 = PostPostGroupAll<PostRiserUs15O0J00GroupAllParameters, TypeRiserUs15O0Step>;
}

#endif
