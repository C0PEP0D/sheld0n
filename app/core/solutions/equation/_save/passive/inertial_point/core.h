#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_INERTIAL_POINT_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_INERTIAL_POINT_CORE_H
#pragma once

// App includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/passive/inertial_point/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveInertialPointStep : public TypePassiveInertialPointStep {
    public:
        using Type = TypePassiveInertialPointStep;
    public:
        TypeParameters parameters;
    public:
        PassiveInertialPointStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(sFlow, parameters.delay) {
        }
};

}

#endif
