#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS__E2_10O0_POS_B_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS__E2_10O0_POS_B_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/tracers__e2_10o0/pos_b/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/tracers__e2_10o0/pos_b/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitTracersE210O0PosBGroup = InitInitGroupAll<InitTracersE210O0PosBGroupAllParameters, TypeObjectStep, InitTracersE210O0PosBGroupMember>;
}

#endif
