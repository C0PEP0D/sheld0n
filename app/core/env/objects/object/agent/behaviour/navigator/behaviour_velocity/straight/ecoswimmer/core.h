#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_STRAIGHT_ECOSWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_STRAIGHT_ECOSWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/straight/ecoswimmer/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourVelocityStraightEcoswimmer : public AgentBehaviourNavigatorBehaviourVelocity<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourVelocityStraightEcoswimmer() {
        }
    public:
        double operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients, const TypeSpaceVector& swimmingDirection) const override {
            const double value = swimmingDirection.dot(direction);
            if(value > 0.0){
                return value;
            } else {
                return 0.0;
            }
        }
};


}

#endif
