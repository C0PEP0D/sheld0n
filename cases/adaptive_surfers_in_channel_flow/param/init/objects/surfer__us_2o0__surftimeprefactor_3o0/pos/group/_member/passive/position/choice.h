#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_3O0_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_3O0_POS_GROUP_MEMBER_PASSIVE_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/position/box/core.h"
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_3o0/pos/group/_member/passive/position/box/parameters.h"

namespace c0p {
    template<typename TypeSurferUs2O0Surftimeprefactor3O0Step>
    using InitSurferUs2O0Surftimeprefactor3O0PosGroupMemberPassivePosition = InitInitPassivePositionBox<InitSurferUs2O0Surftimeprefactor3O0PosGroupMemberPassivePositionBoxParameters, TypeSurferUs2O0Surftimeprefactor3O0Step>;
}

#endif