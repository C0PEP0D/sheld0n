#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_VELOCITY_VALUE_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_VELOCITY_VALUE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/velocity/value/prop.h"

namespace c0p {

// Group members velocity value initialisation parameters
struct InitObjectPosPassiveVelocityValueParameters {
	TypeSpaceVector value = TypeSpaceVector::Zero();
};

}

#endif
