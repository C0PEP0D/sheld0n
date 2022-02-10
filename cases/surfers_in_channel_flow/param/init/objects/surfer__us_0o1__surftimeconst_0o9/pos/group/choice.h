#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O9_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O9_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o9/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o9/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O1Surftimeconst0O9Step>
    using InitSurferUs0O1Surftimeconst0O9PosGroup = InitInitGroupAll<InitSurferUs0O1Surftimeconst0O9PosGroupAllParameters, TypeSurferUs0O1Surftimeconst0O9Step, InitSurferUs0O1Surftimeconst0O9PosGroupMember>;
}

#endif
