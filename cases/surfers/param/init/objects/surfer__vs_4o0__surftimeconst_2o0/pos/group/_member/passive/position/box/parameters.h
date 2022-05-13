#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_2O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_2O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitSurferVs4O0Surftimeconst2O0PosGroupMemberPassivePositionBoxParameters {
    // Center of the box
    TypeSpaceVector c0 = TypeSpaceVector::Constant(M_PI);
    // Size of the box
    TypeSpaceVector l = TypeSpaceVector::Constant(2.0 * M_PI);
};

}

#endif
