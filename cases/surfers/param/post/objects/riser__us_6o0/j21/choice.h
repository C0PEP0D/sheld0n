#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_6O0_J21_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_6O0_J21_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_6o0/j21/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs6O0Step>
    using PostRiserUs6O0J21 = PostPostGroupAll<PostRiserUs6O0J21GroupAllParameters, TypeRiserUs6O0Step>;
}

#endif
