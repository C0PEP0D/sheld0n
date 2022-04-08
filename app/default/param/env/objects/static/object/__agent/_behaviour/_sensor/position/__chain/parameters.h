#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CHAIN_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CHAIN_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/chain/prop.h"
#include "param/parameters.h"

// include of the chain to sense
#include "param/env/objects/odor/choice.h"

namespace c0p {

// Chain position sensor parameters
struct ObjectAgentBehaviourSensorPositionChainParameters {
    // Chain type to sense
    using TypeChainStep = OdorStep; // Replace Odor by the name of the chain
    // Object chain index
    const unsigned int chainIndex = 0;
};

}

#endif
