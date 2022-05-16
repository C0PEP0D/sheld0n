#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_BASIS_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_BASIS_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/passive/basis/random/core.h"
#include "param/init/objects/object/pos/passive/basis/random/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitObjectPosPassiveBasis = InitInitPassiveBasisRandom<InitObjectPosPassiveBasisRandomParameters, TypeObjectStep>;
}

#endif
