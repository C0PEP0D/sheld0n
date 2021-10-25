#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_7O0__SURFTIMECONST_2O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_7O0__SURFTIMECONST_2O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_7o0__surftimeconst_2o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_7o0__surftimeconst_2o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs7O0Surftimeconst2O0Step>
    using InitSurferUs7O0Surftimeconst2O0PosGroup = InitInitGroupAll<InitSurferUs7O0Surftimeconst2O0PosGroupAllParameters, TypeSurferUs7O0Surftimeconst2O0Step, InitSurferUs7O0Surftimeconst2O0PosGroupMember>;
}

#endif
