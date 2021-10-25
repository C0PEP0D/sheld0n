#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_4O5_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_4O5_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/position/box/core.h"
#include "param/init/objects/riser__us_4o5/pos/group/_member/passive/position/box/parameters.h"

namespace c0p {
    template<typename TypeRiserUs4O5Step>
    using InitRiserUs4O5PosGroupMemberPassivePosition = InitInitPassivePositionBox<InitRiserUs4O5PosGroupMemberPassivePositionBoxParameters, TypeRiserUs4O5Step>;
}

#endif
