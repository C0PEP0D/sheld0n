#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SKEW_SYMMETRIC_ORTHOGONAL_TO_AXIS_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SKEW_SYMMETRIC_ORTHOGONAL_TO_AXIS_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/skew_symmetric_orthogonal_to_axis/prop.h"
#include "param/parameters.h"

namespace c0p {

// Skew symmetric part of the flow velocity gradients sensor parameters
struct ObjectAgentBehaviourSensorVelocityGradientsSkewSymmetricOrthogonalToAxisParameters {
	const unsigned int axis = 0;
};

}

#endif
