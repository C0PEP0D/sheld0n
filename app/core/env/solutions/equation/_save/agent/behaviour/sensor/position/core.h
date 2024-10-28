#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/prop.h"

namespace c0p {

template<typename AgentActiveStep>
class AgentBehaviourSensorPosition {
    public:
        AgentBehaviourSensorPosition(std::shared_ptr<Objects> sObjects) {
        }
    public:
        virtual TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const = 0;
    public:
        virtual TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const {
            return {};
        }
};


}

#endif
