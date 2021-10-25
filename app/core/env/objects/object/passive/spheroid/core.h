#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_SPHEROID_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_SPHEROID_CORE_H
#pragma once

// App includes
#include "core/env/objects/object/passive/spheroid/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveSpheroidStep : public TypePassiveSpheroidStep {
    public:
        using Type = TypePassiveSpheroidStep;
        using TypeStateStatic = typename Type::TypeStateStatic;
    public:
        TypeParameters parameters;
    public:
        PassiveSpheroidStep(const std::shared_ptr<Flow>& sFlow, Objects<ObjectsParameters>* pObjects) : Type(sFlow, 1.0) {
            setProportion(parameters.proportion);
        }
};

}

#endif
