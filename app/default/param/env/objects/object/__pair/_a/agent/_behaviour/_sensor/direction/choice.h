#ifndef C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#pragma once

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/core.h"
#include "param/env/objects/object/pair/_a/agent/_behaviour/_sensor/direction/accurate/parameters.h"
namespace c0p {
    template<typename ObjectPairAAgentActiveStep>
    using ObjectPairAAgentBehaviourSensorDirection = AgentBehaviourSensorDirectionAccurate<ObjectPairAAgentBehaviourSensorDirectionAccurateParameters, ObjectPairAAgentActiveStep>;
}

#endif
