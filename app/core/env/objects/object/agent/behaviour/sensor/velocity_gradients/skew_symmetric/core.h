#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SKEW_SYMMETRIC_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_SKEW_SYMMETRIC_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/skew_symmetric/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsSkewSymmetric : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsSkewSymmetricAsym() {
        }
    public:
        TypeSpaceMatrix operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
            const TypeSpaceMatrix velocityGradients = stepActive.sFlow->getVelocityGradients(stepActive.cX(pState), t);
            return 0.5 * (velocityGradients - velocityGradients.transpose());
        }
};


}

#endif
