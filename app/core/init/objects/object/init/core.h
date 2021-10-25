#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_INIT_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_INIT_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <map>
#include <string>
// app includes
#include "core/init/objects/object/init/prop.h"

namespace c0p {

template<typename TypeObjectStep>
class InitInitInit {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
    public:
        InitInitInit(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep) {
        }
    public:
        virtual void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) = 0;
};

}

#endif
