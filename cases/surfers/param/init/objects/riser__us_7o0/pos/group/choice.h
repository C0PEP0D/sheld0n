#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_7O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_7O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/riser__us_7o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/riser__us_7o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs7O0Step>
    using InitRiserUs7O0PosGroup = InitInitGroupAll<InitRiserUs7O0PosGroupAllParameters, TypeRiserUs7O0Step, InitRiserUs7O0PosGroupMember>;
}

#endif
