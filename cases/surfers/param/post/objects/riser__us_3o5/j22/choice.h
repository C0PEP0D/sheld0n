#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O5_J22_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O5_J22_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_3o5/j22/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs3O5Step>
    using PostRiserUs3O5J22 = PostPostGroupAll<PostRiserUs3O5J22GroupAllParameters, TypeRiserUs3O5Step>;
}

#endif
