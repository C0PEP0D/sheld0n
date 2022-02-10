#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O8_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O8_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o8/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o8/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O5Surftimeconst0O8Step>
    using InitSurferUs0O5Surftimeconst0O8PosGroup = InitInitGroupAll<InitSurferUs0O5Surftimeconst0O8PosGroupAllParameters, TypeSurferUs0O5Surftimeconst0O8Step, InitSurferUs0O5Surftimeconst0O8PosGroupMember>;
}

#endif
