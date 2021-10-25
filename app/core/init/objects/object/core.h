#ifndef C0P_CORE_INIT_OBJECTS_OBJECT_CORE_H
#define C0P_CORE_INIT_OBJECTS_OBJECT_CORE_H
#pragma once

// std include
#include <memory> // shared_ptr
#include <map>
#include <string>
// app includes
#include "core/init/objects/object/init/core.h"
#include "core/init/objects/object/prop.h"

namespace c0p {

class InitInitBase {
    public:
        InitInitBase() {
        }
    public:
        virtual void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) = 0;
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class InitInit : public InitInitBase {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
        TypeParameters<TypeObjectStep> parameters;
    public:
        InitInit(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
        }
    public:
        void operator()(TypeRef<TypeVector<Eigen::Dynamic>> state) override {
            for(const std::shared_ptr<InitInitInit<TypeObjectStep>>& sInitObjectStep : parameters.data) {
                (*sInitObjectStep)(state);
            }
        }
};

}

#endif
