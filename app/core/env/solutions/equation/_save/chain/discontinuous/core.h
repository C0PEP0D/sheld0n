#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_DISCONTINUOUS_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_CHAIN_DISCONTINUOUS_CORE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// app includes
#include "core/env/objects/object/chain/discontinuous/prop.h"

namespace c0p {

template<typename TypeParameters>
class ChainDiscontinuousStep : public TypeChainDiscontinuousStep<typename TypeParameters::TypeMemberStep> {
    public:
        using Type = TypeChainDiscontinuousStep<typename TypeParameters::TypeMemberStep>;
        using TypeMemberStep = typename TypeParameters::TypeMemberStep;
    public:
        TypeParameters parameters;
    public:
        std::shared_ptr<Flow> sFlow;
        std::shared_ptr<Objects> sObjects;
    public:
        ChainDiscontinuousStep(const std::shared_ptr<Flow>& p_sFlow, std::shared_ptr<Objects> p_sObjects) : Type(std::make_shared<TypeMemberStep>(p_sFlow, sObjects), 0.0, 0, TypeParameters::closed), parameters(), sFlow(p_sFlow), sObjects(p_sObjects) {
            Type::sManagedStep->dl = parameters.dl;
            Type::sManagedStep->interpolationOrder = parameters.interpolationOrder;
        }
};

}

#endif
