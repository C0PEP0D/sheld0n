#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_VELOCITY_FLOW_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_POS_PASSIVE_VELOCITY_FLOW_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/passive/velocity/flow/prop.h"

namespace c0p {

// Group members velocity initialisation to flow velocity parameters
struct InitObjectPosPassiveVelocityFlowParameters {
	// Initial velocity difference between the flow velocity and the particle
	TypeSpaceVector velocityDifference = TypeSpaceVector::Zero();
};

}

#endif
