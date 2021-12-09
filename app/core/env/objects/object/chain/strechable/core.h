#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_STRECHABLE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_STRECHABLE_CORE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// app includes
#include "core/env/objects/object/chain/strechable/prop.h"

namespace c0p {

template<typename TypeParameters>
class ChainStrechableStep : public TypeChainStrechableStep<typename TypeParameters::TypeMemberStep> {
    public:
        using Type = TypeChainStrechableStep<typename TypeParameters::TypeMemberStep>;
        using TypeMemberStep = typename TypeParameters::TypeMemberStep;
    public:
        TypeParameters parameters;
    public:
        std::shared_ptr<Flow> sFlow;
        std::shared_ptr<Objects> sObjects;
    public:
        ChainStrechableStep(const std::shared_ptr<Flow>& p_sFlow, std::shared_ptr<Objects> p_sObjects) : Type(std::make_shared<TypeMemberStep>(p_sFlow, sObjects), 0.0, 0), parameters(), sFlow(p_sFlow), sObjects(p_sObjects) {
            Type::dl = parameters.dl;
            Type::interpolationOrder = parameters.interpolationOrder;
        }
};

}

#endif
