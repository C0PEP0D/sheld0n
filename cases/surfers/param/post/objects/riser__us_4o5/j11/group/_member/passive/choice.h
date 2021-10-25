#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O5_J11_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O5_J11_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/jac/core.h"
#include "param/post/objects/riser__us_4o5/j11/group/_member/passive/jac/parameters.h"

namespace c0p {
    template<typename TypeRiserUs4O5Step>
    using PostRiserUs4O5J11GroupMemberPassive = PostPostPassiveJac<PostRiserUs4O5J11GroupMemberPassiveJacParameters, TypeRiserUs4O5Step>;
}

#endif
