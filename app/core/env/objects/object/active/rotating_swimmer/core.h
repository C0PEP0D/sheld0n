#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ROTATING_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ROTATING_SWIMMER_CORE_H
#pragma once

// std includes
#include <memory>
// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/active/rotating_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename ActivePassiveStep>
class ActiveRotatingSwimmerStep : public TypeActiveStep<ActivePassiveStep>  {
    public:
        using Type = TypeActiveStep<ActivePassiveStep>;
        using TypeStateVectorDynamic = typename Type::TypeStateVectorDynamic;
    public:
        TypeParameters parameters;
        std::shared_ptr<TypeLocalAxisSwimStep<ActivePassiveStep>> sStepLocalAxisSwim;
        std::shared_ptr<TypeAxisRotateStep<ActivePassiveStep>> sStepAxisRotate;
    public:
        ActiveRotatingSwimmerStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : 
            Type(ActivePassiveStep(sFlow, sObjects)), 
            sStepLocalAxisSwim(std::make_shared<TypeLocalAxisSwimStep<ActivePassiveStep>>(parameters.velocity)),
            sStepAxisRotate(std::make_shared<TypeAxisRotateStep<ActivePassiveStep>>(parameters.angularVelocity))
        {
            Type::register_actuator(sStepLocalAxisSwim);
            Type::register_actuator(sStepAxisRotate);
        }
};

}

#endif
