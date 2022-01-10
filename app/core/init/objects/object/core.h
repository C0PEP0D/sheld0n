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

class InitInitStaticBase {
    public:
        InitInitStaticBase() {
        }
    public:
        virtual void operator()(double* pState) = 0;
};

class InitInitDynamicBase {
    public:
        InitInitDynamicBase() {
        }
    public:
        virtual void operator()(std::vector<double>& state) = 0;
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class InitInitStatic : public InitInitStaticBase {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
        TypeParameters<TypeObjectStep> parameters;
    public:
        InitInitStatic(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
        }
    public:
        void operator()(double* pState) override {
            for(const std::shared_ptr<InitInitInitStatic<TypeObjectStep>>& sInitObjectStep : parameters.sInits) {
                (*sInitObjectStep)(pState);
            }
        }
};

template<template<typename> typename TypeParameters, typename TypeObjectStep>
class InitInitDynamic : public InitInitDynamicBase {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
        TypeParameters<TypeObjectStep> parameters;
    public:
        InitInitDynamic(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep), parameters(sObjectStep) {
        }
    public:
        void operator()(std::vector<double>& state) override {
            for(const std::shared_ptr<InitInitInitDynamic<TypeObjectStep>>& sInitObjectStep : parameters.sInits) {
                (*sInitObjectStep)(state);
            }
        }
};

}

#endif
