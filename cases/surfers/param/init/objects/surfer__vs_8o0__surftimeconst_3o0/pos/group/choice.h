#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_3O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_3O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__vs_8o0__surftimeconst_3o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__vs_8o0__surftimeconst_3o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitSurferVs8O0Surftimeconst3O0PosGroup = InitInitGroupAll<InitSurferVs8O0Surftimeconst3O0PosGroupAllParameters, TypeObjectStep, InitSurferVs8O0Surftimeconst3O0PosGroupMember>;
}

#endif
