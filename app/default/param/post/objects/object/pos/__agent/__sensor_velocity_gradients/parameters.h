#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_SENSOR_VELOCITY_GRADIENTS_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_POS_AGENT_SENSOR_VELOCITY_GRADIENTS_PARAMETERS_H
#pragma once

// std include
#include <string>
// app include
#include "core/post/objects/object/post/agent/sensor_velocity_gradients/prop.h"

namespace c0p {

struct PostObjectPosAgentSensorVelocityGradientsParameters {
    const std::string name = "sJ";
};

}

#endif
