#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_CHOICE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_CHOICE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/prop.h"

namespace c0p {

template<typename AgentActiveStep, typename Behaviour>
class AgentStep : public TypeAgentStep<AgentActiveStep, Behaviour> {
    public:
        using Type = TypeAgentStep<AgentActiveStep, Behaviour>;
        using TypeStateVectorDynamic = typename Type::TypeStateVectorDynamic;
    public:
        AgentStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(AgentActiveStep(sFlow, sObjects), std::make_shared<Behaviour>(sObjects)) {

        }
};

}

#endif
