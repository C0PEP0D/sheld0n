#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PX_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PX_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "param/post/objects/dobject/px/group/_member/passive/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostDobjectPxGroupMember = PostDobjectPxGroupMemberPassive<TypeMemberStep>;
}

#endif
