#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_NB_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_NB_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "param/init/objects/dobject/nb/group/_member/passive/position/choice.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using InitDobjectNbGroupMemberPassive = InitDobjectNbGroupMemberPassivePosition<TypeDobjectStep>;
}

#endif
