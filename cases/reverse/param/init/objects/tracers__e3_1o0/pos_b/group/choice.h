#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS__E3_1O0_POS_B_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS__E3_1O0_POS_B_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/tracers__e3_1o0/pos_b/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/tracers__e3_1o0/pos_b/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitTracersE31O0PosBGroup = InitInitGroupAll<InitTracersE31O0PosBGroupAllParameters, TypeObjectStep, InitTracersE31O0PosBGroupMember>;
}

#endif
