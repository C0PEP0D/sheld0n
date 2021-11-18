#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourTrackerBehaviourDirection {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        AgentBehaviourTrackerBehaviourDirection() {
        }
    public:
        virtual TypeSpaceVector operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep& stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const = 0;
    public:
        virtual TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const {
            return {};
        }
};


}

#endif
