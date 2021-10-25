#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_3O0__SURFTIMECONST_7O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_3O0__SURFTIMECONST_7O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_3o0__surftimeconst_7o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_3o0__surftimeconst_7o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs3O0Surftimeconst7O0Step>
    using InitSurferUs3O0Surftimeconst7O0PosGroup = InitInitGroupAll<InitSurferUs3O0Surftimeconst7O0PosGroupAllParameters, TypeSurferUs3O0Surftimeconst7O0Step, InitSurferUs3O0Surftimeconst7O0PosGroupMember>;
}

#endif
