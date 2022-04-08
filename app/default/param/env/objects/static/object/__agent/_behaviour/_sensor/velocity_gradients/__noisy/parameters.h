#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_NOISY_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_NOISY_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/noisy/prop.h"
#include "param/parameters.h"

namespace c0p {

// Noisy flow velocity gradients sensor parameters
struct ObjectAgentBehaviourSensorVelocityGradientsNoisyParameters {
    const TypeScalar noiseIntensity = 1.0 * 1.0/Parameters::cTime;
};

}

#endif
