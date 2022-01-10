#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_NOISY_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_NOISY_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/noisy/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsNoisy : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        using TypeAgentStateStatic = typename AgentActiveStep::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsNoisy() {
        }
    public:
        TypeSpaceMatrix operator()(const TypeRef<const TypeAgentStateStatic>& state, const double& t, const AgentActiveStep&  stepActive) const override {
            TypeSpaceMatrix velocityGradients = stepActive.sFlow->getJacobian(stepActive.cX(state), t);
            for(unsigned int i = 0; i < velocityGradients.rows(); i++) {
                for(unsigned int j = 0; j < velocityGradients.cols(); j++) {
                    velocityGradients(i,j) += parameters.noiseIntensity * rand0m::standardNormalDistribution(rand0m::engine);
                }
            }
            return velocityGradients;
        }
};


}

#endif
