#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_10O0__REORIENTATIONTIME_1O0_ORIENT_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_10O0__REORIENTATIONTIME_1O0_ORIENT_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_1o0__surftimeconst_10o0__reorientationtime_1o0/orient/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_10o0__reorientationtime_1o0/orient/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeconst10O0Reorientationtime1O0Step>
    using InitSurferUs1O0Surftimeconst10O0Reorientationtime1O0OrientGroup = InitInitGroupAll<InitSurferUs1O0Surftimeconst10O0Reorientationtime1O0OrientGroupAllParameters, TypeSurferUs1O0Surftimeconst10O0Reorientationtime1O0Step, InitSurferUs1O0Surftimeconst10O0Reorientationtime1O0OrientGroupMember>;
}

#endif
