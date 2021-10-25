#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O0_J10_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O0_J10_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_3o0/j10/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs3O0Step>
    using PostRiserUs3O0J10 = PostPostGroupAll<PostRiserUs3O0J10GroupAllParameters, TypeRiserUs3O0Step>;
}

#endif
