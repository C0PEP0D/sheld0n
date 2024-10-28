#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_BOTH_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_BOTH_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/pair/both/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class InitInitPairBoth : public InitInitInitStatic<TypeObjectStep> {
    public:
        TypeParameters parameters;
        typename TypeParameters::TypeInitInitA<typename TypeObjectStep::TypeAStep> initA;
        typename TypeParameters::TypeInitInitB<typename TypeObjectStep::TypeBStep> initB;
    public:
        using InitInitInitStatic<TypeObjectStep>::sObjectStep;
    public:
        InitInitPairBoth(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitStatic<TypeObjectStep>(p_sObjectStep), initA(sObjectStep->sAStep), initB(sObjectStep->sBStep) {
        }
    public:
        void operator()(double* pState) override {
            initA(sObjectStep->aState(pState));
            initB(sObjectStep->bState(pState));
        };
};

}

#endif
