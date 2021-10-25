#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_3O5_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_3O5_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/riser__us_3o5/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/riser__us_3o5/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeRiserUs3O5Step>
    using InitRiserUs3O5PosGroup = InitInitGroupAll<InitRiserUs3O5PosGroupAllParameters, TypeRiserUs3O5Step, InitRiserUs3O5PosGroupMember>;
}

#endif
