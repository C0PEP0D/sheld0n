#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_AGENT_BEHAVIOUR_CUSTOM_SWIMMER_CORE_H
#pragma once

// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/agent/behaviour/custom/swimmer/prop.h"

namespace c0p {

template<template<typename> typename TypeParameters, typename AgentActiveStep>
class AgentBehaviourCustomSwimmer : public sl0::sa0::Behaviour<AgentActiveStep> {
    public:
        using Type = sl0::sa0::Behaviour<AgentActiveStep>;
    public:
        TypeParameters<AgentActiveStep> parameters;
    public:
        AgentBehaviourCustomSwimmer(std::shared_ptr<Objects> sObjects) {
        }
    public:
        TypeContainer<TypeSpaceVector> positions(const double* pState, const AgentActiveStep& stepActive) const override {
            return parameters.positions(pState, stepActive);
        }
    public:
        void operator()(const double* pState, const double& t, const AgentActiveStep& stepActive) const override {
            parameters(pState, t, stepActive);
        }
};


}

#endif
