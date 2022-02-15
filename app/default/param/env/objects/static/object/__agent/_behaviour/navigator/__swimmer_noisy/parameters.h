#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_SWIMMER_NOISY_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_SWIMMER_NOISY_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/swimmer_noisy/prop.h"
#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a navigator that controls its swimming direction
struct ObjectAgentBehaviourNavigatorSwimmerNoisyParameters {
    const TypeScalar noiseIntensity = 1.0;
};

}

#endif
