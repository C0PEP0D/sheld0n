#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_0O25_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_0O25_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/surfer__us_0o8__surftimeprefactor_0o25/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/surfer__us_0o8__surftimeprefactor_0o25/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitSurferUs0O8Surftimeprefactor0O25PosGroup = InitInitGroupAll<InitSurferUs0O8Surftimeprefactor0O25PosGroupAllParameters, TypeObjectStep, InitSurferUs0O8Surftimeprefactor0O25PosGroupMember>;
}

#endif
