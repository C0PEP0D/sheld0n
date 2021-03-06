#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_NOISY_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_NOISY_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/noisy/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorDirectionNoisy : public AgentBehaviourSensorDirection<AgentActiveStep> {
    public:
        using Type = AgentBehaviourSensorDirection<AgentActiveStep>;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorDirectionNoisy(std::shared_ptr<Objects> sObjects) : Type(sObjects) {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
            TypeSpaceVector direction = parameters.direction;
            for(unsigned int i = 0; i < direction.size(); i++) {
                direction[i] += parameters.noiseIntensity * rand0m::standardNormalDistribution(rand0m::engine);
            }
            return direction.normalized();
        }
};


}

#endif
