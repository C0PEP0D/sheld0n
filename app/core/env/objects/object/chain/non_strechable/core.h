#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_NON_STRECHABLE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_NON_STRECHABLE_CORE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// app includes
#include "core/env/objects/object/chain/non_strechable/prop.h"

namespace c0p {

template<typename TypeParameters>
class ChainNonStrechableStep : public TypeChainNonStrechableStep<TypeParameters::size, typename TypeParameters::TypeMemberStep> {
    public:
        using Type = TypeChainNonStrechableStep<TypeParameters::size, typename TypeParameters::TypeMemberStep>;
        using TypeMemberStep = typename TypeParameters::TypeMemberStep;
    public:
        TypeParameters parameters;
    public:
        ChainNonStrechableStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(std::make_shared<TypeMemberStep>(sFlow, pObjects), 1.0, 0), parameters() {
            Type::interpolationOrder = parameters.interpolationOrder;
            Type::length = parameters.length;
        }
};

}

#endif
