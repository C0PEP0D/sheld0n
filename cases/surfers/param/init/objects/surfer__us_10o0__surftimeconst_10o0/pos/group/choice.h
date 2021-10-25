#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_10O0__SURFTIMECONST_10O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_10O0__SURFTIMECONST_10O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_10o0__surftimeconst_10o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_10o0__surftimeconst_10o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs10O0Surftimeconst10O0Step>
    using InitSurferUs10O0Surftimeconst10O0PosGroup = InitInitGroupAll<InitSurferUs10O0Surftimeconst10O0PosGroupAllParameters, TypeSurferUs10O0Surftimeconst10O0Step, InitSurferUs10O0Surftimeconst10O0PosGroupMember>;
}

#endif
