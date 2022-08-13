#ifndef C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate position sensor parameters
struct ObjectAgentBehaviourSensorPositionAccurateParameters {
    // Position sensed
    TypeSpaceVector position = {0.0, 0.0, 0.0};
};

}

#endif
