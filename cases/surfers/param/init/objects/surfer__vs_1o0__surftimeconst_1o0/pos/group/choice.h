#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_1O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_1O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__vs_1o0__surftimeconst_1o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__vs_1o0__surftimeconst_1o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitSurferVs1O0Surftimeconst1O0PosGroup = InitInitGroupAll<InitSurferVs1O0Surftimeconst1O0PosGroupAllParameters, TypeObjectStep, InitSurferVs1O0Surftimeconst1O0PosGroupMember>;
}

#endif
