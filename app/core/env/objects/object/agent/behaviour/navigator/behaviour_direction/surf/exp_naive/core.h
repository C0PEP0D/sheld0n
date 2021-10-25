#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_NAIVE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_SURF_EXP_NAIVE_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/surf/exp_naive/prop.h"
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep, typename TypeSensorDirection, typename TypeSensorVelocityGradients, typename TypeBehaviourTimeHorizon>
class AgentBehaviourNavigatorBehaviourDirectionSurfExpNaive : public AgentBehaviourNavigatorBehaviourDirection<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
        TypeSensorDirection sensorDirection;
        TypeSensorVelocityGradients sensorVelocityGradients;
        TypeBehaviourTimeHorizon behaviourTimeHorizon;
    public:
        AgentBehaviourNavigatorBehaviourDirectionSurfExpNaive() {
        }
    public:
        TypeSpaceVector operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive) const override {
            const TypeSpaceVector direction = sensorDirection(state, t, stepActive);
            const TypeSpaceMatrix velocityGradients = sensorVelocityGradients(state, t, stepActive);
            return (naiveExp(velocityGradients * behaviourTimeHorizon(state, t, stepActive, velocityGradients), parameters.order)).transpose() * direction;
        }
        
        // computes sum(A^n / n!) over from n = 0 to order
        TypeSpaceMatrix naiveExp(const TypeRef<const TypeSpaceMatrix> A, std::size_t order) const {
            double n_fact = 1.0;
            TypeSpaceMatrix A_n = TypeSpaceMatrix::Identity();
            TypeSpaceMatrix result = A_n / n_fact;
            for(std::size_t n = 1; n < order; n++) {
                n_fact *= n;
                A_n *= A;
                result += A_n/n_fact;
            }
            return result;
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeAgentStateStatic>& state, const AgentActiveStep& stepActive) const override {
            return sensorVelocityGradients.positions(state, stepActive);
        }
};


}

#endif
