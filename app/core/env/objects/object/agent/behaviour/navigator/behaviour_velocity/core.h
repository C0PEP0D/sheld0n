#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourVelocity {
    public:
        AgentBehaviourNavigatorBehaviourVelocity() {
        }
    public:
        virtual double operator()(const double* pState, const double& t, const AgentActiveStep& stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients, const TypeSpaceVector& swimmingDirection) const = 0;
    public:
        virtual TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const {
            return {};
        }
};

}

#endif
