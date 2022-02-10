#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O0_POS_GROUP_MEMBER_PASSIVE_POSITION_BOX_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitSurferUs2O0Surftimeconst0O0PosGroupMemberPassivePositionBoxParameters {
    // Center of the box
    TypeSpaceVector c0 = TypeSpaceVector({4.0 * M_PI, -1.0, 1.5 * M_PI}); // c0y = 0.0
    // Size of the box
    TypeSpaceVector l = TypeSpaceVector({4.0 * M_PI, 0.0, 1.5 * M_PI}); // ly = 2.0
};

}

#endif
