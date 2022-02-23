#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_2O75_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_2O75_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_2o75/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_0o1__surftimeprefactor_2o75/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O1Surftimeprefactor2O75Step>
    using InitSurferUs0O1Surftimeprefactor2O75PosGroup = InitInitGroupAll<InitSurferUs0O1Surftimeprefactor2O75PosGroupAllParameters, TypeSurferUs0O1Surftimeprefactor2O75Step, InitSurferUs0O1Surftimeprefactor2O75PosGroupMember>;
}

#endif
