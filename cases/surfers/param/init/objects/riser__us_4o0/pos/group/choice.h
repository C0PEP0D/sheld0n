#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_4O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_4O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/riser__us_4o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/riser__us_4o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs4O0Step>
    using InitRiserUs4O0PosGroup = InitInitGroupAll<InitRiserUs4O0PosGroupAllParameters, TypeRiserUs4O0Step, InitRiserUs4O0PosGroupMember>;
}

#endif
