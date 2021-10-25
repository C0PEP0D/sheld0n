#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O5_J20_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O5_J20_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_2o5/j20/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs2O5Step>
    using PostRiserUs2O5J20 = PostPostGroupAll<PostRiserUs2O5J20GroupAllParameters, TypeRiserUs2O5Step>;
}

#endif
