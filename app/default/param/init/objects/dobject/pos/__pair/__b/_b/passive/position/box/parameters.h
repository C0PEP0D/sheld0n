#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PAIR_B_B_PASSIVE_POSITION_BOX_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_POS_PAIR_B_B_PASSIVE_POSITION_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitDobjectPosPairBBPassivePositionBoxParameters {
    // Center of the box
    TypeSpaceVector c0 = TypeSpaceVector::Constant(0.0);
    // Length of the bow for each dimension
    TypeSpaceVector l = TypeSpaceVector::Constant(1.0);
};

}

#endif
