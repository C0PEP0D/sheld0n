#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CHAIN_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_SENSOR_POSITION_CHAIN_CORE_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/chain/prop.h"
#include "core/env/objects/object/agent/behaviour/sensor/position/core.h"

namespace c0p {

template<typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourSensorPositionChain : public AgentBehaviourSensorPosition<AgentActiveStep> {
    public:
        using Type = AgentBehaviourSensorPosition<AgentActiveStep>;
    public:
        TypeParameters parameters;
    public:
        AgentBehaviourSensorPositionChain(std::shared_ptr<Objects> p_sObjects) : Type(p_sObjects), sObjects(p_sObjects) {
        }
    public:
        TypeSpaceVector operator()(const double* pState, const double& t, const AgentActiveStep&  stepActive) const override {
            return std::dynamic_pointer_cast<TypeParameters::TypeChainStep>(sObjects->sStepsDynamic[chainIndex])->closest(sObjects->statesDynamic[parameters.chainIndex].data, stepActive.cX(pState));
        }
    public:
        std::shared_ptr<Objects> sObjects;
};


}

#endif
