#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_NB_MANAGER_MANAGED_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_NB_MANAGER_MANAGED_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/mobject/nb/manager/_managed/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/add/core.h"
#include "param/init/objects/mobject/nb/manager/_managed/group/add/parameters.h"

namespace c0p {
    template<typename TypeMobjectStep>
    using InitMobjectNbManagerManagedGroup = InitInitGroupAdd<InitMobjectNbManagerManagedGroupAddParameters, TypeMobjectStep, InitMobjectNbManagerManagedGroupMember>;
}

#endif
