#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS__E2_1O0_POS_A_GROUP_MEMBER_PAIR_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS__E2_1O0_POS_A_GROUP_MEMBER_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/pair/a/core.h"
#include "param/init/objects/tracers__e2_1o0/pos_a/group/_member/pair/a/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitTracersE21O0PosAGroupMemberPair = InitInitPairA<InitTracersE21O0PosAGroupMemberPairAParameters, TypeObjectStep>;
}

#endif
