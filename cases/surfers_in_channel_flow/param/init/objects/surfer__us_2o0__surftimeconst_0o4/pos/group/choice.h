#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O4_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O4_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o4/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_2o0__surftimeconst_0o4/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs2O0Surftimeconst0O4Step>
    using InitSurferUs2O0Surftimeconst0O4PosGroup = InitInitGroupAll<InitSurferUs2O0Surftimeconst0O4PosGroupAllParameters, TypeSurferUs2O0Surftimeconst0O4Step, InitSurferUs2O0Surftimeconst0O4PosGroupMember>;
}

#endif