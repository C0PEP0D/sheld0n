#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_A_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_A_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/pair/a/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class InitInitPairA : public InitInitInit<TypeObjectStep> {
    public:
        TypeParameters parameters;
        typename TypeParameters::TypeInitInitA<typename TypeObjectStep::TypeAStep> initA;
    public:
        using InitInitInit<TypeObjectStep>::sObjectStep;
    public:
        InitInitPairA(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInit<TypeObjectStep>(p_sObjectStep), initA(sObjectStep->sAStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            initA(sObjectStep->aState(state));
        };
};

}

#endif
