#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourSensorPosition {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        AgentBehaviourSensorPosition() {
        }
    public:
        virtual TypeSpaceVector operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive) const = 0;
    public:
        virtual TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const {
            return {};
        }
};


}

#endif
