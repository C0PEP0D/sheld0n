#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_AXIS_RANDOM_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_PASSIVE_AXIS_RANDOM_CORE_H
#pragma once

// std includes
#include <string>
#include <map>
// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/init/passive/axis/random/prop.h"

namespace c0p {

template<typename Parameters, typename TypeObjectStep>
class InitInitPassiveAxisRandom : public InitInitInit<TypeObjectStep> {
    public:
        Parameters parameters;
    public:
        using InitInitInit<TypeObjectStep>::sObjectStep;
    public:
        using InitInitInit<TypeObjectStep>::InitInitInit;
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            sObjectStep->axis(state) = TypeSpaceVector::Random();
        };
};

}

#endif
