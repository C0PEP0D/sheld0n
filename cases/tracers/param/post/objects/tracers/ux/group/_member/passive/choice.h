#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_UX_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_UX_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/velocity/core.h"
#include "param/post/objects/tracers/ux/group/_member/passive/velocity/parameters.h"

namespace c0p {
    template<typename TypeTracersStep>
    using PostTracersUxGroupMemberPassive = PostPostPassiveVelocity<PostTracersUxGroupMemberPassiveVelocityParameters, TypeTracersStep>;
}

#endif
