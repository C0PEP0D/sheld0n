#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorDirection, typename TypeSensorVelocityGradients, typename TypeBehaviourTimeHorizon>
class AgentBehaviourNavigatorBehaviourDirectionSurfExp : public AgentBehaviourNavigatorBehaviourDirection<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
        TypeSensorDirection sensorDirection;
        TypeSensorVelocityGradients sensorVelocityGradients;
        TypeBehaviourTimeHorizon behaviourTimeHorizon;
    public:
        AgentBehaviourNavigatorBehaviourDirectionSurfExp() {
        }
    public:
        TypeSpaceVector operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive) const override {
            const TypeSpaceVector direction = sensorDirection(state, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(state, t, stepActive);
            return ((velocityGradients * behaviourTimeHorizon(state, t, stepActive, velocityGradients)).exp()).transpose() * direction;
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const override {
            return sensorVelocityGradients.positions(state, stepActive);
        }
};


}

#endif
