#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeBehaviourTimeHorizon>
class AgentBehaviourNavigatorBehaviourDirectionSurfExp : public AgentBehaviourNavigatorBehaviourDirection<AgentActiveStep> {
    public:
        TypeParameters parameters;
        // Sub behaviours
        TypeBehaviourTimeHorizon behaviourTimeHorizon;
    public:
        AgentBehaviourNavigatorBehaviourDirectionSurfExp() {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients) const override {
            return ((velocityGradients * behaviourTimeHorizon(pState, t, stepActive, velocityGradients)).exp()).transpose() * direction;
        }
};


}

#endif
