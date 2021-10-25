#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SYMMETRIC_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SYMMETRIC_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/symmetric/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsSymmetric : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsSymmetric() {
        }
    public:
        TypeSpaceMatrix operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive) const override {
            const TypeSpaceMatrix J = stepActive.sFlow->getJacobian(stepActive.cX(state), t);
            return 0.5 * (J + J.transpose());
        }
};


}

#endif
