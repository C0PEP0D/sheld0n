#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_BASIS_VALUE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_BASIS_VALUE_CORE_H
#pragma once

// std includes
#include <string>
#include <map>
// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/init/passive/basis/value/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class InitInitPassiveBasisValue : public InitInitInitStatic<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        using InitInitInitStatic<TypeObjectStep>::InitInitInitStatic;
    public:
        void operator()(double* pState) override {
            sObjectStep->axis(pState, 0) = parameters.valueAxis0;
            sObjectStep->axis(pState, 1) = parameters.valueAxis1;
        };
};

}

#endif
