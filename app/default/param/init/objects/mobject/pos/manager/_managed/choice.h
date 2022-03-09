#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_POS_MANAGER_MANAGED_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_POS_MANAGER_MANAGED_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "param/init/objects/mobject/pos/manager/_managed/group/choice.h"

namespace c0p {
    template<typename TypeManagedStep>
    using InitMobjectPosManagerManaged = InitMobjectPosManagerManagedGroup<TypeManagedStep>;
}

#endif
