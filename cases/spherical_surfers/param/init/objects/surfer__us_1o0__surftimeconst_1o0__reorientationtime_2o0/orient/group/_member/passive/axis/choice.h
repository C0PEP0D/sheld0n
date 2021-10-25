#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_1O0__REORIENTATIONTIME_2O0_ORIENT_GROUP_MEMBER_PASSIVE_AXIS_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_1O0__REORIENTATIONTIME_2O0_ORIENT_GROUP_MEMBER_PASSIVE_AXIS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/axis/random/core.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_1o0__reorientationtime_2o0/orient/group/_member/passive/axis/random/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeconst1O0Reorientationtime2O0Step>
    using InitSurferUs1O0Surftimeconst1O0Reorientationtime2O0OrientGroupMemberPassiveAxis = InitInitPassiveAxisRandom<InitSurferUs1O0Surftimeconst1O0Reorientationtime2O0OrientGroupMemberPassiveAxisRandomParameters, TypeSurferUs1O0Surftimeconst1O0Reorientationtime2O0Step>;
}

#endif
