#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_15O0__SURFTIMECONST_6O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_15O0__SURFTIMECONST_6O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_15o0__surftimeconst_6o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_15o0__surftimeconst_6o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs15O0Surftimeconst6O0Step>
    using InitSurferUs15O0Surftimeconst6O0PosGroup = InitInitGroupAll<InitSurferUs15O0Surftimeconst6O0PosGroupAllParameters, TypeSurferUs15O0Surftimeconst6O0Step, InitSurferUs15O0Surftimeconst6O0PosGroupMember>;
}

#endif
