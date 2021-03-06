#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/direction/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorDirectionAccurate : public AgentBehaviourSensorDirection<AgentActiveStep> {
    public:
        using Type = AgentBehaviourSensorDirection<AgentActiveStep>;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorDirectionAccurate(std::shared_ptr<Objects> sObjects) : Type(sObjects) {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
            return parameters.direction;
        }
};


}

#endif
