#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_10O0_J11_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_10O0_J11_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_10o0/j11/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs10O0Step>
    using PostRiserUs10O0J11Group = PostPostGroupAll<PostRiserUs10O0J11GroupAllParameters, TypeRiserUs10O0Step>;
}

#endif