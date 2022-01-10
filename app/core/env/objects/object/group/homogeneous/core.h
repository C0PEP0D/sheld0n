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
class GroupHomogeneousStep : public TypeGroupHomogeneousStep<typename TypeParameters::TypeMemberStep, TypeParameters::size> {
    public:
        using Type = TypeGroupHomogeneousStep<typename TypeParameters::TypeMemberStep, TypeParameters::size>;
        using Type::TypeMemberStep;
    public:
        TypeParameters parameters;
    public:
        GroupHomogeneousStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : TypeGroupHomogeneousStep<typename TypeParameters::TypeMemberStep, TypeParameters::size>(std::make_shared<typename TypeParameters::TypeMemberStep>(sFlow, sObjects)), parameters() {
        }
};

}

#endif
