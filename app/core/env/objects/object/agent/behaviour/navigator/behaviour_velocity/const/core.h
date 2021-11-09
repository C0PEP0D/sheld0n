#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourVelocityConst : public AgentBehaviourNavigatorBehaviourVelocity<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourVelocityConst() {
        }
    public:
        double operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients, const TypeSpaceVector& swimmingDirection) const override {
            return 1.0;
        }
};


}

#endif
