#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_POSITION_BOX_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_POSITION_BOX_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/init/passive/position/box/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class InitInitPassivePositionBox : public InitInitInitStatic<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        using InitInitInitStatic<TypeObjectStep>::InitInitInitStatic;
    public:
        void operator()(double* pState) override {
            TypeSpaceVector xInit = parameters.c0;
            TypeSpaceVector xRandom = TypeSpaceVector::Random();
            for(unsigned int i = 0; i < parameters.l.size(); i++) {
                xInit[i] += 0.5 * parameters.l[i] * xRandom[i];
            }
            sObjectStep->x(pState) = xInit;
        };
};

}

#endif
