#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PAIR_B_B_PASSIVE_POSITION_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PAIR_B_B_PASSIVE_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/position/box/core.h"
#include "param/init/objects/dobject/pos/pair/b/_b/passive/position/box/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using InitDobjectPosPairBBPassivePosition = InitInitPassivePositionBox<InitDobjectPosPairBBPassivePositionBoxParameters, TypeDobjectStep>;
}

#endif
