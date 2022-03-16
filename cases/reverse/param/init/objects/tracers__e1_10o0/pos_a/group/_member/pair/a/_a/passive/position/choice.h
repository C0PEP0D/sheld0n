#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS__E1_10O0_POS_A_GROUP_MEMBER_PAIR_A_A_PASSIVE_POSITION_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS__E1_10O0_POS_A_GROUP_MEMBER_PAIR_A_A_PASSIVE_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/position/box/core.h"
#include "param/init/objects/tracers__e1_10o0/pos_a/group/_member/pair/a/_a/passive/position/box/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitTracersE110O0PosAGroupMemberPairAAPassivePosition = InitInitPassivePositionBox<InitTracersE110O0PosAGroupMemberPairAAPassivePositionBoxParameters, TypeObjectStep>;
}

#endif
