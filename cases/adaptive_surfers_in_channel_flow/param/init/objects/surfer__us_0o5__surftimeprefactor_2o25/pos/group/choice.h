#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O25_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O25_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o25/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_0o5__surftimeprefactor_2o25/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O5Surftimeprefactor2O25Step>
    using InitSurferUs0O5Surftimeprefactor2O25PosGroup = InitInitGroupAll<InitSurferUs0O5Surftimeprefactor2O25PosGroupAllParameters, TypeSurferUs0O5Surftimeprefactor2O25Step, InitSurferUs0O5Surftimeprefactor2O25PosGroupMember>;
}

#endif
