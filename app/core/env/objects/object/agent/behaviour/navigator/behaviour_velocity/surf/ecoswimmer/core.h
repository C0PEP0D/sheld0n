#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_ECOSWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_SURF_ECOSWIMMER_CORE_H
#pragma once

// thirdparties
#include <unsupported/Eigen/MatrixFunctions>
// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/surf/ecoswimmer/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorDirection, typename TypeSensorVelocityGradients, typename TypeBehaviourTimeHorizon>
class AgentBehaviourNavigatorBehaviourVelocitySurfEcoswimmer : public AgentBehaviourNavigatorBehaviourVelocity<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
        TypeSensorDirection sensorDirection;
        TypeSensorVelocityGradients sensorVelocityGradients;
        TypeBehaviourTimeHorizon behaviourTimeHorizon;
    public:
        AgentBehaviourNavigatorBehaviourVelocitySurfEcoswimmer() {
        }
    public:
        double operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive, const TypeSpaceVector& swimmingDirection) const override {
            const TypeSpaceVector direction = sensorDirection(state, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(state, t, stepActive);
            const double value = (((velocityGradients * behaviourTimeHorizon(state, t, stepActive, velocityGradients)).exp()).transpose() * swimmingDirection).dot(direction);
            if(value > 0.0){
                return value;
            } else {
                return 0.0;
            }
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const override {
            return sensorVelocityGradients.positions(state, stepActive);
        }
};


}

#endif
