#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_CORE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/group/homogeneous/prop.h"

namespace c0p {

template<typename TypeParameters>
class GroupHomogeneousStep : public TypeGroupHomogeneousStep {
    public:
        using Type = TypeGroupHomogeneousStep;
        using TypeMemberStep = typename TypeParameters::TypeMemberStep;
    public:
        TypeParameters parameters;
        std::shared_ptr<TypeMemberStep> sMemberStep;
    public:
        GroupHomogeneousStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(), parameters(), sMemberStep(std::make_shared<TypeMemberStep>(sFlow, pObjects)) {
            for(unsigned int memberIndex = 0; memberIndex < TypeParameters::size; memberIndex++) {
                Type::registerMember(std::make_shared<TypeMemberStep>(sFlow, pObjects), sMemberStep->stateSize());
            }
        }
};

}

#endif
