#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitTracersPosGroupMemberPassivePositionBoxParameters {
    // Center of the box
    TypeSpaceVector c0 = TypeSpaceVector::Constant(M_PI);
    // Length of the box for each dimension
    TypeSpaceVector l = TypeSpaceVector::Constant(2.0 * M_PI);
};

}

#endif
