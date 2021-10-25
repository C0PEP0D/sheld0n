#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_POINT_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_POINT_CORE_H
#pragma once

// App includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/passive/point/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassivePointStep : public TypePassivePointStep {
    public:
        using Type = TypePassivePointStep;
        using TypeStateStatic = typename Type::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        PassivePointStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(sFlow) {
        }
};

}

#endif
