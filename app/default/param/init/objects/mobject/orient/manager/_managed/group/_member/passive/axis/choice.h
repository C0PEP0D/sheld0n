#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_MEMBER_PASSIVE_AXIS_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_MEMBER_PASSIVE_AXIS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/axis/value/core.h"
#include "param/init/objects/mobject/orient/manager/_managed/group/_member/passive/axis/value/parameters.h"

namespace c0p {
    template<typename TypeMobjectStep>
    using InitMobjectOrientManagerManagedGroupMemberPassiveAxis = InitInitPassiveAxisValue<InitMobjectOrientManagerManagedGroupMemberPassiveAxisValueParameters, TypeMobjectStep>;
}

#endif
