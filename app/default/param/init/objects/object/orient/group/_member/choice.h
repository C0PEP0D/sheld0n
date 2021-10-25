#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_ORIENT_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_ORIENT_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "param/init/objects/object/orient/group/_member/passive/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using InitObjectOrientGroupMember = InitObjectOrientGroupMemberPassive<TypeMemberStep>;
}

#endif
