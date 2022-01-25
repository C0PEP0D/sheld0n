#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_VELOCITY_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_VELOCITY_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/velocity/flow/core.h"
#include "param/init/objects/object/pos/passive/velocity/flow/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitObjectPosPassiveVelocity = InitInitPassiveVelocityFlow<InitObjectPosPassiveVelocityFlowParameters, TypeObjectStep>;
}

#endif
