#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_20O0__SURFTIMECONST_9O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_20O0__SURFTIMECONST_9O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_20o0__surftimeconst_9o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_20o0__surftimeconst_9o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs20O0Surftimeconst9O0Step>
    using InitSurferUs20O0Surftimeconst9O0PosGroup = InitInitGroupAll<InitSurferUs20O0Surftimeconst9O0PosGroupAllParameters, TypeSurferUs20O0Surftimeconst9O0Step, InitSurferUs20O0Surftimeconst9O0PosGroupMember>;
}

#endif
