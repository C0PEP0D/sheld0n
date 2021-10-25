#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_FILTERED_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_FILTERED_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/filtered/prop.h"
#include "param/parameters.h"

namespace c0p {

// Filtered flow velocity gradients sensor parameters.
// Gradient is averaged over measures sampled in a
// box of length l. Samples are spaces by a length dx.
// The number of samples is l over dx
struct ObjectAgentBehaviourSensorVelocityGradientsFilteredParameters {
    // Filtering/Averaging length
    double l = 1.0 * Parameters::cLength;
    // Sampling step
    double dx = 0.5 * l;
};

}

#endif
