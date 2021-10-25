#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourSensorDirection {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        AgentBehaviourSensorDirection() {
        }
    public:
        virtual TypeSpaceVector operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive) const = 0;
};


}

#endif
