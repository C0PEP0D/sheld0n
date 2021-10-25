#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_9O0__SURFTIMECONST_5O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_9O0__SURFTIMECONST_5O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_9o0__surftimeconst_5o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_9o0__surftimeconst_5o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs9O0Surftimeconst5O0Step>
    using InitSurferUs9O0Surftimeconst5O0PosGroup = InitInitGroupAll<InitSurferUs9O0Surftimeconst5O0PosGroupAllParameters, TypeSurferUs9O0Surftimeconst5O0Step, InitSurferUs9O0Surftimeconst5O0PosGroupMember>;
}

#endif
