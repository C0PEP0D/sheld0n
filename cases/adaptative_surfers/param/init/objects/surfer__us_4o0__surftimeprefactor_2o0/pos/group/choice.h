#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_4o0__surftimeprefactor_2o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_4o0__surftimeprefactor_2o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeSurferUs4O0Surftimeprefactor2O0Step>
    using InitSurferUs4O0Surftimeprefactor2O0PosGroup = InitInitGroupAll<InitSurferUs4O0Surftimeprefactor2O0PosGroupAllParameters, TypeSurferUs4O0Surftimeprefactor2O0Step, InitSurferUs4O0Surftimeprefactor2O0PosGroupMember>;
}

#endif
