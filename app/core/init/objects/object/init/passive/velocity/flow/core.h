#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_VELOCITY_FLOW_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_VELOCITY_FLOW_CORE_H
#pragma once

// std includes
#include <string>
#include <map>
// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/init/passive/velocity/flow/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class InitInitPassiveVelocityFlow : public InitInitInitStatic<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        using InitInitInitStatic<TypeObjectStep>::InitInitInitStatic;
    public:
        void operator()(double* pState) override {
            sObjectStep->u(pState) = sObjectsStep->sFlow->getVelocity(sObjectStep->x(pState), 0.0) + parameters.velocityDifference;
        };
};

}

#endif
