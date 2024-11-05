#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_ODOR_TRACKER_BEHAVIOUR_DIRECTION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/odor_tracker/behaviour_direction/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourOdorTrackerBehaviourDirection {
    public:
        AgentBehaviourOdorTrackerBehaviourDirection() {
        }
    public:
        virtual TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep& stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const = 0;
    public:
        virtual TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const {
            return {};
        }
};


}

#endif
