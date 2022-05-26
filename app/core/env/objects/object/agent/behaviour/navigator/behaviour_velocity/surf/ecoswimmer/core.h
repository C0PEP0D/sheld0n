#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_ECOSWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_ECOSWIMMER_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/ecoswimmer/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeBehaviourTimeHorizon>
class AgentBehaviourNavigatorBehaviourVelocitySurfEcoswimmer : public AgentBehaviourNavigatorBehaviourVelocity<AgentActiveStep> {
    public:
        TypeParameters parameters;
        TypeBehaviourTimeHorizon behaviourTimeHorizon;
    public:
        AgentBehaviourNavigatorBehaviourVelocitySurfEcoswimmer() {
        }
    public:
        double operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients, const TypeSpaceVector& swimmingDirection) const override {
            const double value = (((velocityGradients * behaviourTimeHorizon(pState, t, stepActive, velocityGradients)).exp()).transpose() * swimmingDirection).normalized().dot(direction);
            if(value > parameters.threshold){
                return 1.0;
            } else {
                return 0.0;
            }
        }
};


}

#endif
