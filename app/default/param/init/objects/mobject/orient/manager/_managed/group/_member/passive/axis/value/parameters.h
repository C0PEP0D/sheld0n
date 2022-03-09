#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_MEMBER_PASSIVE_AXIS_VALUE_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_ORIENT_MANAGER_MANAGED_GROUP_MEMBER_PASSIVE_AXIS_VALUE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/axis/value/prop.h"

namespace c0p {

// Random box position initialisation parameters
struct InitMobjectOrientManagerManagedGroupMemberPassiveAxisValueParameters {
    // Center of the box
    TypeSpaceVector value = TypeSpaceVector({0.0, 1.0, 0.0});
};

}

#endif
