#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_NOISY_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_NOISY_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/noisy/prop.h"
#include "param/parameters.h"

namespace c0p {

// Noisy direction sensor parameters
struct ObjectAgentBehaviourSensorDirectionNoisyParameters {
    // Direction sensed
    const TypeSpaceVector direction = {1.0, 0.0, 0.0};
    const TypeScalar noiseIntensity = 1.0;
};

}

#endif
