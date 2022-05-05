#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_CUSTOM_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_CUSTOM_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/custom/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/core.h"

namespace c0p {

template<template<typename> typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourNavigatorBehaviourDirectionCustom : public AgentBehaviourNavigatorBehaviourDirection<AgentActiveStep> {
    public:
        TypeParameters<AgentActiveStep> parameters;
    public:
        AgentBehaviourNavigatorBehaviourDirectionCustom() {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& direction, const TypeSpaceMatrix& velocityGradients) const override {
            return parameters(pState, t, stepActive, direction, velocityGradients);
        }
};


}

#endif
