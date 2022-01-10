#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/position/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorPositionAccurate : public AgentBehaviourSensorPosition<AgentActiveStep> {
    public:
        using Type = AgentBehaviourSensorPosition<AgentActiveStep>;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorPositionAccurate(std::shared_ptr<Objects> sObjects) : Type(sObjects) {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
            return parameters.position;
        }
};


}

#endif
