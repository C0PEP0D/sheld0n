#ifndef C0P_PARAM_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/group/all/prop.h"

#include "param/parameters.h"

namespace c0p {

// Group member position initialisation on a line parameters
struct InitMobjectOrientManagerManagedGroupAllParameters {
    // Origin of the line
    TypeSpaceVector origin = TypeSpaceVector::Constant(M_PI);
    // Length and direction of the line
    TypeSpaceVector l = 10.0 * Parameters::cLength * TypeSpaceVector::Random().normalized();
};

}

#endif
