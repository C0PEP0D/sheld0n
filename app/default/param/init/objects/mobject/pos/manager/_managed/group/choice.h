#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_POS_MANAGER_MANAGED_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_POS_MANAGER_MANAGED_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/mobject/pos/manager/_managed/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/line/core.h"
#include "param/init/objects/mobject/pos/manager/_managed/group/line/parameters.h"

namespace c0p {
    template<typename TypeMobjectStep>
    using InitMobjectPosManagerManagedGroup = InitInitGroupLine<InitMobjectPosManagerManagedGroupLineParameters, TypeMobjectStep, InitMobjectPosManagerManagedGroupMember>;
}

#endif
