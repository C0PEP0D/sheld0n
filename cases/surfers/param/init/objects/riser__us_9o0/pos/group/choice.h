#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_9O0_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_9O0_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/riser__us_9o0/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/riser__us_9o0/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs9O0Step>
    using InitRiserUs9O0PosGroup = InitInitGroupAll<InitRiserUs9O0PosGroupAllParameters, TypeRiserUs9O0Step, InitRiserUs9O0PosGroupMember>;
}

#endif
