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
        using TypeStateStatic = typename Type::TypeStateStatic;
    public:
        AgentStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(AgentActiveStep(sFlow, pObjects), std::make_shared<Behaviour>(pObjects)) {

        }
    public:
        TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeStateStatic>& state) const override {
            std::vector<TypeSpaceVector> result = Type::positions(state);
            std::vector<TypeSpaceVector> sensorPositions = Type::positions(state);
            return result;
        }
};

}

#endif
