#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_STRAIGHT_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_STRAIGHT_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/straight/prop.h"
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourTrackerBehaviourDirectionStraight : public AgentBehaviourTrackerBehaviourDirection<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourTrackerBehaviourDirectionStraight() {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const override {
            return (position - stepActive.cX(pState)).normalized();
        }
};


}

#endif
