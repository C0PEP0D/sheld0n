#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_RELATIVE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_RELATIVE_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/pair/relative/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class InitInitPairRelative : public InitInitInitStatic<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        InitInitPairRelative(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(double* pState) override {
            sObjectStep->sBStep->x(sObjectStep->bState(pState)) = sObjectStep->sAStep->cX(sObjectStep->cAState(pState)) + parameters.position;
        };
};

}

#endif
