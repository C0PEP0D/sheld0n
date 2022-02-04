#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_UY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_UY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/flow_velocity/core.h"
#include "param/post/objects/pagent/uy/group/_member/passive/flow_velocity/parameters.h"

namespace c0p {
    template<typename TypePagentStep>
    using PostPagentUyGroupMemberPassive = PostPostPassiveFlowVelocity<PostPagentUyGroupMemberPassiveFlowVelocityParameters, TypePagentStep>;
}

#endif
