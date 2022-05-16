#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_BASIS_VALUE_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_BASIS_VALUE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/basis/value/prop.h"

namespace c0p {

// Group members value axis initialisation parameters
struct InitObjectPosPassiveBasisValueParameters {
	const TypeSpaceVector valueAxis0 = TypeSpaceVector({1.0, 0.0, 0.0});
	const TypeSpaceVector valueAxis1 = TypeSpaceVector({0.0, 1.0, 0.0});
};

}

#endif
