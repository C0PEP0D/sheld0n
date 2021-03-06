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
class InitInitInitDynamic {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
    public:
        InitInitInitDynamic(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep) {
        }
    public:
        virtual void operator()(std::vector<double>& state) = 0;
};

template<typename TypeObjectStep>
class InitInitInitStatic : public InitInitInitDynamic<TypeObjectStep> {
    public:
        using InitInitInitDynamic<TypeObjectStep>::sObjectStep;
    public:
        InitInitInitStatic(std::shared_ptr<TypeObjectStep> p_sObjectStep) : InitInitInitDynamic<TypeObjectStep>(p_sObjectStep) {
        }
    public:
    	void operator()(std::vector<double>& state) override {
    		operator()(state.data());
    	}
        virtual void operator()(double* pState) = 0;
};

template<typename TypeObjectStep>
class InitInitInitManager {
    public:
        std::shared_ptr<TypeObjectStep> sObjectStep;
    public:
        InitInitInitManager(std::shared_ptr<TypeObjectStep> p_sObjectStep) : sObjectStep(p_sObjectStep) {
        }
    public:
    	virtual void operator()(std::vector<std::vector<double>>& state) = 0;
};

}

#endif
