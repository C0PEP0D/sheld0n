#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_VELOCITY_GRADIENTS_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/velocity_gradients/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourSensorVelocityGradients {
    public:
        AgentBehaviourSensorVelocityGradients() {
        }
    public:
        virtual TypeSpaceMatrix operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const = 0;
    public:
        virtual TypeContainer<TypeSpaceVector> positions(const double* state, const AgentActiveStep& stepActive) const {
            return {};
        }
};


}

#endif
