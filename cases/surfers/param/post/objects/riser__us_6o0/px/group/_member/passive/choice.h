#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PX_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PX_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_6o0/px/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs6O0Step>
    using PostRiserUs6O0PxGroupMemberPassive = PostPostPassivePosition<PostRiserUs6O0PxGroupMemberPassivePositionParameters, TypeRiserUs6O0Step>;
}

#endif
