#ifndef C0P_CORE_ENV_OBJECTS_CORE_H
#define C0P_CORE_ENV_OBJECTS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
#include <execution>
// lib includes
#include "sl0/group/dynamic.h"
// app includes
#include "core/env/objects/prop.h"

namespace c0p {

class Objects;

class StepObjectsStatic : public sl0::StepGroupDynamic<TypeVector, DIM, TypeView> {
    public:
        using Type = sl0::StepGroupDynamic<TypeVector, DIM, TypeView>;
        using typename Type::TypeStateVectorDynamic;
    public:
        // env
        std::shared_ptr<Flow> sFlow;
    public:
        StepObjectsStatic(const std::shared_ptr<Flow>& p_sFlow) : Type(), sFlow(p_sFlow) {
        }
    public:
        TypeStateVectorDynamic operator()(const double* pState, const double& t) const override {
            sFlow->prepare(positions(pState), t);
            return Type::operator()(pState, t);
        }
};

class Objects {
    public:
        using TypeStepDynamic = sl0::StepGroupDynamicHomogeneousBase<TypeVector, DIM, TypeView>;
    public:
        Objects(const std::shared_ptr<Flow>& sFlow) : sSolver(std::make_shared<TypeSolver>()), t(0.0), sStepStatic(std::make_shared<StepObjectsStatic>(sFlow)), stateStatic(sStepStatic->stateSize(), 0.0) {
        }
        void update(const double& dt) {
            // static
            (*sSolver)(*sStepStatic, stateStatic.data(), stateStatic.size(), t, dt);
            (*sStepStatic).update(stateStatic, t);
            // dynamic
            std::for_each(std::execution::par_unseq, dynamicIndexs.cbegin(), dynamicIndexs.cend(), [this, dt](const unsigned int& dynamicIndex){ 
                (*sSolver)(*sStepsDynamic[dynamicIndex], statesDynamic[dynamicIndex].data(), statesDynamic[dynamicIndex].size(), t, dt);
                (*sStepsDynamic[dynamicIndex]).update(statesDynamic[dynamicIndex], t);
            });
            // t
            t += dt;
        }
    public:
        void addDynamicObject(std::shared_ptr<TypeStepDynamic> p_sStepDynamic) {
            sStepsDynamic.push_back(p_sStepDynamic);
            statesDynamic.emplace_back();
            if(dynamicIndexs.empty()) {
                dynamicIndexs.push_back(0);
            } else {
                dynamicIndexs.push_back(dynamicIndexs.back() + 1);
            }
        }
    public:
        std::shared_ptr<TypeSolver> sSolver;
        double t;
    public:
        std::shared_ptr<StepObjectsStatic> sStepStatic;
        std::vector<double> stateStatic;
    public:
        std::vector<std::shared_ptr<TypeStepDynamic>> sStepsDynamic;
        std::vector<std::vector<double>> statesDynamic;
        std::vector<std::size_t> dynamicIndexs;
};

}

#endif
