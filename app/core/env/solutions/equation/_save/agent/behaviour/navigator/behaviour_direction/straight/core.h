#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_STRAIGHT_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_STRAIGHT_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/straight/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourDirectionStraight : public AgentBehaviourNavigatorBehaviourDirection<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourDirectionStraight() {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients) const override {
            return direction;
        }
};


}

#endif
