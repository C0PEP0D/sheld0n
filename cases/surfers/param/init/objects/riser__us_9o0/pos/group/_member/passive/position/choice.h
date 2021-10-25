#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_9O0_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_9O0_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/position/box/core.h"
#include "param/init/objects/riser__us_9o0/pos/group/_member/passive/position/box/parameters.h"

namespace c0p {
    template<typename TypeRiserUs9O0Step>
    using InitRiserUs9O0PosGroupMemberPassivePosition = InitInitPassivePositionBox<InitRiserUs9O0PosGroupMemberPassivePositionBoxParameters, TypeRiserUs9O0Step>;
}

#endif
