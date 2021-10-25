#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_SIMPLE_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_SIMPLE_CORE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// app includes
#include "core/env/objects/object/chain/simple/prop.h"

namespace c0p {

template<typename TypeParameters>
class ChainSimpleStep : public TypeChainSimpleStep<TypeParameters::size, typename TypeParameters::TypeMemberStep> {
    public:
        using Type = TypeChainSimpleStep<TypeParameters::size, typename TypeParameters::TypeMemberStep>;
        using TypeMemberStep = typename TypeParameters::TypeMemberStep;
    public:
        TypeParameters parameters;
    public:
        ChainSimpleStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(std::make_shared<TypeMemberStep>(sFlow, pObjects)), parameters() {
            Type::dlMax = parameters.dlMax;
        }
};

}

#endif
