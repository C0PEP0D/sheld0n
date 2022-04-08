#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_ORIENT_GROUP_MEMBER_PASSIVE_AXIS_VALUE_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_ORIENT_GROUP_MEMBER_PASSIVE_AXIS_VALUE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/axis/value/prop.h"

namespace c0p {

// Group members value axis initialisation parameters
struct InitDobjectOrientGroupMemberPassiveAxisValueParameters {
	TypeSpaceVector value = TypeSpaceVector({0.0, 1.0, 0.0});
};

}

#endif
