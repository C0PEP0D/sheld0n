#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_LOCAL_DIRECTION_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_LOCAL_DIRECTION_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/local_direction/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate flow velocity gradients sensor parameters
struct ObjectAgentBehaviourSensorVelocityGradientsLocalDirectionParameters {
	const TypeSpaceVector localDirection = Eigen::AngleAxis(Parameters::cAngle, TypeSpaceVector({0.0, 0.0, 1.0})) * TypeSpaceVector({1.0, 0.0, 0.0});
};

}

#endif
