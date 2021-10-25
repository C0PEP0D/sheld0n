#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_J10_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_J10_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "param/post/objects/tracers/j10/group/_member/passive/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostTracersJ10GroupMember = PostTracersJ10GroupMemberPassive<TypeMemberStep>;
}

#endif
