#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/mobject/orient/manager/_managed/choice.h"
// choose your init
#include "core/init/objects/object/init/manager/all/core.h"
#include "param/init/objects/mobject/orient/manager/all/parameters.h"

namespace c0p {
    template<typename TypeMobjectStep>
    using InitMobjectOrientManager = InitInitManagerAll<InitMobjectOrientManagerAllParameters, TypeMobjectStep, InitMobjectOrientManagerManaged>;
}

#endif
