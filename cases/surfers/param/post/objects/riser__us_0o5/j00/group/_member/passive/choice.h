#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_0O5_J00_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_0O5_J00_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/jac/core.h"
#include "param/post/objects/riser__us_0o5/j00/group/_member/passive/jac/parameters.h"

namespace c0p {
    template<typename TypeRiserUs0O5Step>
    using PostRiserUs0O5J00GroupMemberPassive = PostPostPassiveJac<PostRiserUs0O5J00GroupMemberPassiveJacParameters, TypeRiserUs0O5Step>;
}

#endif
