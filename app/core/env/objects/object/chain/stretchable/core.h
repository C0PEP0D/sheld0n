#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_STRECHABLE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_STRECHABLE_CORE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// app includes
#include "core/env/objects/object/chain/strechable/prop.h"

namespace c0p {

template<typename TypeParameters>
class ChainStrechableStep : public TypeChainStrechableStep<TypeParameters::size, typename TypeParameters::TypeMemberStep> {
    public:
        using Type = TypeChainStrechableStep<TypeParameters::size, typename TypeParameters::TypeMemberStep>;
        using TypeMemberStep = typename TypeParameters::TypeMemberStep;
    public:
        TypeParameters parameters;
    public:
        Objects<ObjectsParameters>* pObjects;
    public:
        ChainStrechableStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(std::make_shared<TypeMemberStep>(sFlow, pObjects), 1.0, 0), parameters() {
            Type::interpolationOrder = parameters.interpolationOrder;
            Type::dl = parameters.dl;
        }
};

}

#endif
