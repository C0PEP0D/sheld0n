#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/mobject/orient/manager/_managed/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/mobject/orient/manager/_managed/group/all/parameters.h"

namespace c0p {
    template<typename TypeMobjectStep>
    using InitMobjectOrientManagerManagedGroup = InitInitGroupAll<InitMobjectOrientManagerManagedGroupAllParameters, TypeMobjectStep, InitMobjectOrientManagerManagedGroupMember>;
}

#endif
