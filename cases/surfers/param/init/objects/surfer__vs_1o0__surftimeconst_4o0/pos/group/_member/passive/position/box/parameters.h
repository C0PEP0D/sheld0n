#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_4O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_4O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitSurferVs1O0Surftimeconst4O0PosGroupMemberPassivePositionBoxParameters {
    // Center of the box
    TypeSpaceVector c0 = TypeSpaceVector::Constant(M_PI);
    // Size of the box
    TypeSpaceVector l = TypeSpaceVector::Constant(2.0 * M_PI);
};

}

#endif
