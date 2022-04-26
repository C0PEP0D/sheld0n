#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_INERTIAL_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_INERTIAL_SWIMMER_CORE_H
#pragma once

// std includes
#include <memory>
// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/active/inertial_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename ActivePassiveStep>
class ActiveInertialSwimmerStep : public TypeActiveStep<ActivePassiveStep>  {
    public:
        using Type = TypeActiveStep<ActivePassiveStep>;
        using TypeStateVectorDynamic = typename Type::TypeStateVectorDynamic;
    public:
        TypeParameters parameters;
        std::shared_ptr<TypeInertialSwimStep<ActivePassiveStep>> sStepInertialSwim;
    public:
        ActiveInertialSwimmerStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : 
            Type(ActivePassiveStep(sFlow, sObjects)), 
            sStepInertialSwim(std::make_shared<TypeInertialSwimStep<ActivePassiveStep>>(parameters.velocity))
        {
            Type::registerActuator(sStepInertialSwim);
        }

        ActiveInertialSwimmerStep(const ActiveLocalAxisSwimmerStep& step) : Type(step)
   		{
   			Type::clearActuators();
   			sStepInertialSwim = std::make_shared<TypeInertialSwimStep<ActivePassiveStep>>(parameters.velocity);
   			Type::registerActuator(sStepInertialSwim);
   		}
};

}

#endif
