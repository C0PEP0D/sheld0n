#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_DISTANCE_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PAIR_DISTANCE_CORE_H
#pragma once

// app includes
#include "core/init/objects/object/init/pair/distance/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeObjectStep>
class InitInitPairDistance : public InitInitInit<TypeObjectStep> {
    public:
        TypeParameters parameters;
    public:
        using InitInitInit<TypeObjectStep>::sObjectStep;
    public:
        InitInitPairDistance(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInit<TypeObjectStep>(p_sObjectStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            sObjectStep->sBStep->x(sObjectStep->bState(state)) = sObjectStep->sAStep->x(sObjectStep->aState(state)) + TypeSpaceVector::Random().normalized() * parameters.distance;
        };
};

}

#endif
