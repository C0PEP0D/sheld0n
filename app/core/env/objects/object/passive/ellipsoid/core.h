#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_ELLIPSOID_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_ELLIPSOID_CORE_H
#pragma once

// App includes
#include "core/env/objects/object/passive/ellipsoid/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveEllipsoidStep : public TypePassiveEllipsoidStep {
    public:
        using Type = TypePassiveEllipsoidStep;
    public:
        TypeParameters parameters;
    public:
        PassiveEllipsoidStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(sFlow, std::vector<double>({1.0, 1.0, 1.0})) {
            setDimensions(parameters.dimensions);
        }
};

}

#endif
