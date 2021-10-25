#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O5_J21_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O5_J21_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/jac/core.h"
#include "param/post/objects/riser__us_2o5/j21/group/_member/passive/jac/parameters.h"

namespace c0p {
    template<typename TypeRiserUs2O5Step>
    using PostRiserUs2O5J21GroupMemberPassive = PostPostPassiveJac<PostRiserUs2O5J21GroupMemberPassiveJacParameters, TypeRiserUs2O5Step>;
}

#endif
