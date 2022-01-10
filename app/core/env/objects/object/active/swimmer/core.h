#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_SWIMMER_CORE_H
#pragma once

// std includes
#include <memory>
// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/active/swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename ActivePassiveStep>
class ActiveSwimmerStep : public TypeActiveStep<ActivePassiveStep>  {
    public:
        using Type = TypeActiveStep<ActivePassiveStep>;
    public:
        TypeParameters parameters;
        std::shared_ptr<TypeSwimStep<ActivePassiveStep>> sStepSwim;

        ActiveSwimmerStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : Type(ActivePassiveStep(sFlow, sObjects)), sStepSwim(std::make_shared<TypeSwimStep<ActivePassiveStep>>(parameters.velocity)) {
            Type::register_actuator(sStepSwim);
        }
};

}

#endif
