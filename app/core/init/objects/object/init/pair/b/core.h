#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_B_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_B_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/pair/a/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class InitInitPairB : public InitInitInitStatic<TypeObjectStep> {
    public:
        TypeParameters parameters;
        typename TypeParameters::TypeInitInitB<typename TypeObjectStep::TypeAStep> initB;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        InitInitPairB(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep), initB(sObjectStep->sBStep) {
        }
    public:
        void operator()(double* pState) override {
            initB(sObjectStep->bState(pState));
        };
};

}

#endif
