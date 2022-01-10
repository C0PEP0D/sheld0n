#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_ACCURATE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_ACCURATE_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/accurate/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradientsAccurate : public AgentBehaviourSensorVelocityGradients<AgentActiveStep> {
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorVelocityGradientsAccurate() {
        }
    public:
        TypeSpaceMatrix operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
            return stepActive.sFlow->getJacobian(stepActive.cX(pState), t);
        }
};


}

#endif
