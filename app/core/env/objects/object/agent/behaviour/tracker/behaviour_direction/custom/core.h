#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_TRACKER_BEHAVIOUR_DIRECTION_CUSTOM_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/custom/prop.h"
#include "core/env/objects/object/agent/behaviour/tracker/behaviour_direction/core.h"

namespace c0p {

template<template<typename> typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourTrackerBehaviourDirectionCustom : public AgentBehaviourTrackerBehaviourDirection<AgentActiveStep> {
    public:
        TypeParameters<AgentActiveStep> parameters;
    public:
        AgentBehaviourTrackerBehaviourDirectionCustom() {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& position, const TypeSpaceMatrix& velocityGradients) const override {
            return parameters(pState, t, stepActive, position, velocityGradients);
        }
};


}

#endif
