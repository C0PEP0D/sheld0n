#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_ORIENT_GROUP_MEMBER_PASSIVE_AXIS_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_ORIENT_GROUP_MEMBER_PASSIVE_AXIS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/axis/random/core.h"
#include "param/init/objects/object/orient/group/_member/passive/axis/random/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitObjectOrientGroupMemberPassiveAxis = InitInitPassiveAxisRandom<InitObjectOrientGroupMemberPassiveAxisRandomParameters, TypeObjectStep>;
}

#endif
