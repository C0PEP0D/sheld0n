#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PAIR_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your init
#include "core/init/objects/object/init/pair/distance/core.h"
#include "param/init/objects/dobject/pos/pair/distance/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using InitDobjectPosPair = InitInitPairDistance<InitDobjectPosPairDistanceParameters, TypeDobjectStep>;
}

#endif
