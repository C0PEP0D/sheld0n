#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_ORIENT_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_ORIENT_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/dobject/orient/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/dobject/orient/group/all/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using InitDobjectOrientGroup = InitInitGroupAll<InitDobjectOrientGroupAllParameters, TypeDobjectStep, InitDobjectOrientGroupMember>;
}

#endif
