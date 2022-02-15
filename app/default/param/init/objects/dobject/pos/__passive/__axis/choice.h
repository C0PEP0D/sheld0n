#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PASSIVE_AXIS_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PASSIVE_AXIS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/axis/random/core.h"
#include "param/init/objects/dobject/pos/passive/axis/random/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using InitDobjectPosPassiveAxis = InitInitPassiveAxisRandom<InitDobjectPosPassiveAxisRandomParameters, TypeDobjectStep>;
}

#endif
