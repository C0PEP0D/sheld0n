#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0__REORIENTATIONTIME_1O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0__REORIENTATIONTIME_1O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitSurferUs1O0Surftimeconst8O0Reorientationtime1O0PosGroupMemberPassivePositionBoxParameters {
    // Center of the box
    TypeSpaceVector c0 = TypeSpaceVector::Constant(M_PI);
    // Size of the box
    TypeSpaceVector l = TypeSpaceVector::Constant(2.0 * M_PI);
};

}

#endif
