#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O5_J12_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O5_J12_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_4o5/j12/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs4O5Step>
    using PostRiserUs4O5J12 = PostPostGroupAll<PostRiserUs4O5J12GroupAllParameters, TypeRiserUs4O5Step>;
}

#endif
