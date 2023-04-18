#ifndef C0P_PARAM_OBJECTS_OBJECT_POS_GROUP_CIRCLE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_POS_GROUP_CIRCLE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/group/circle/prop.h"

#include "param/parameters.h"

namespace c0p {

// Group member position initialisation on a circle parameters
struct InitObjectPosGroupCircleParameters {
    // Origin of the circle
    TypeSpaceVector center = TypeSpaceVector::Constant(M_PI);
    // Radius of the circle in the x direction
    TypeSpaceVector rx = 0.1 * Parameters::cLength * TypeSpaceVector({1.0, 0.0, 0.0});
    // Radius of the circle in the y direction
    TypeSpaceVector ry = 0.1 * Parameters::cLength * TypeSpaceVector({0.0, 1.0, 0.0});
};

}

#endif
