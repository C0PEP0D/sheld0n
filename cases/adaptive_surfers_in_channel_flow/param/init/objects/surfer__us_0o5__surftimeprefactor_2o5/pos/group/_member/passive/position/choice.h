#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O5_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O5_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/position/box/core.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o5/pos/group/_member/passive/position/box/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O5Surftimeprefactor2O5Step>
    using InitSurferUs0O5Surftimeprefactor2O5PosGroupMemberPassivePosition = InitInitPassivePositionBox<InitSurferUs0O5Surftimeprefactor2O5PosGroupMemberPassivePositionBoxParameters, TypeSurferUs0O5Surftimeprefactor2O5Step>;
}

#endif