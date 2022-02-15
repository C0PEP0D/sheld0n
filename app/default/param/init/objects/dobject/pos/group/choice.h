#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/dobject/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/dobject/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using InitDobjectPosGroup = InitInitGroupAll<InitDobjectPosGroupAllParameters, TypeDobjectStep, InitDobjectPosGroupMember>;
}

#endif
