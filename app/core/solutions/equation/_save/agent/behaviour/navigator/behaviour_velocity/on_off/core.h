#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_ON_OFF_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_ON_OFF_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/on_off/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourVelocityOnOff : public AgentBehaviourNavigatorBehaviourVelocity<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourNavigatorBehaviourVelocityOnOff() {
        }
    public:
        double operator()(const double* pState, const double& t, const AgentActiveStep& stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients, const TypeSpaceVector& swimmingDirection) const override {
            if(swimmingDirection.dot(direction) > parameters.threshold) {
                return 1.0;
            } else {
                return 0.0;
            }
        }
};


}

#endif
