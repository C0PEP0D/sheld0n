#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O5_PX_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O5_PX_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_3o5/px/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs3O5Step>
    using PostRiserUs3O5PxGroupMemberPassive = PostPostPassivePosition<PostRiserUs3O5PxGroupMemberPassivePositionParameters, TypeRiserUs3O5Step>;
}

#endif
