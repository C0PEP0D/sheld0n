#ifndef C0P_CORE_INIT_OBJECTS_CORE_H
#define C0P_CORE_INIT_OBJECTS_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <string>
#include <map>
// app includes
#include "core/init/objects/prop.h"

namespace c0p {

template<typename TypeParameters>
class InitObjects {
    public:
        std::shared_ptr<TypeObjects::Type::TypeStep> sObjectsStep;
        TypeParameters parameters;
    public:
        InitObjects(const TypeObjects& objects) : parameters(objects), sObjectsStep(objects.sStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) {
            for(const unsigned int& memberIndex : sObjectsStep->memberIndexs) {
                (*parameters.data[memberIndex])(sObjectsStep->memberState(state, memberIndex));
            }
        }
};

}

#endif
