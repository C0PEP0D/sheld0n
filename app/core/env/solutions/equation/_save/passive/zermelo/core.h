#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_ZERMELO_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PASSIVE_ZERMELO_CORE_H
#pragma once

// App includes
#include "core/env/objects/object/passive/zermelo/prop.h"

namespace c0p {

template<typename TypeParameters>
class PassiveZermeloStep : public TypePassiveZermeloStep {
    public:
        using Type = TypePassiveZermeloStep;
    public:
        TypeParameters parameters;
    public:
        PassiveZermeloStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(sFlow, 1.0) {
            factor = parameters.factor;
        }
};

}

#endif
