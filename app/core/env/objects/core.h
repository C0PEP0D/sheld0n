#ifndef C0P_CORE_ENV_OBJECTS_CORE_H
#define C0P_CORE_ENV_OBJECTS_CORE_H
#pragma once

// std includes
#include <string>
#include <memory>
// lib includes
#include "sl0/group/dynamic.h"
// app includes
#include "core/env/objects/prop.h"

namespace c0p {

template<typename TypeParameters>
class Objects;

template<typename TypeObjectsParameters>
class StepObjects : public sl0::StepGroupDynamic<TypeVector, DIM, TypeRef, TypeView, StepObject> {
    public:
        using Type = sl0::StepGroupDynamic<TypeVector, DIM, TypeRef, TypeView, StepObject>;
    public:
        // env
        std::shared_ptr<Flow> sFlow;
        Objects<TypeObjectsParameters>* pObjects;
    public:
        StepObjects(const std::shared_ptr<Flow>& p_sFlow, Objects<TypeObjectsParameters>* p_pObjects) : Type(), sFlow(p_sFlow), pObjects(p_pObjects) {
        }
    public:
        TypeVector<Eigen::Dynamic> operator()(const TypeRef<const TypeVector<Eigen::Dynamic>>& state, const double& t) const override {
            sFlow->prepare(positions(state), t);
            return Type::operator()(state, t);
        }
    //public:
        //TypeContainer<TypeSpaceVector> positions(const TypeRef<const TypeVector<Eigen::Dynamic>>& state) const override {
        //    TypeContainer<TypeSpaceVector> result;
        //    result.reserve(state.size() / DIM);
        //    for(unsigned int i = 0; i < state.size(); i += DIM) {
        //        result.emplace_back();
        //        for(unsigned int j = 0; j < DIM; j++) {
        //            result.back()[j] = state[i + j];
        //        }
        //    }
        //    return result;
        //}
};

template<typename TypeParameters>
class Objects : public sl0::ObjectDynamic<TypeSolver, StepObjects<TypeParameters>> {
    public:
        using Type = sl0::ObjectDynamic<TypeSolver, StepObjects<TypeParameters>>;
    public:
        TypeParameters parameters;
        std::shared_ptr<Flow> sFlow;
    public:
        Objects(const std::shared_ptr<Flow>& p_sFlow) : Type(std::make_shared<StepObjects<TypeParameters>>(p_sFlow, this)), parameters(p_sFlow, this), sFlow(p_sFlow) {
            for(const std::shared_ptr<StepObject> sMemberStep : parameters.data) {
                addMember(sMemberStep, sMemberStep->stateSize());
            }
        }
    public:
        // member management
        void addMember(std::shared_ptr<StepObject> sMemberStep, const unsigned int& stateSize) {
            state.conservativeResize(state.size() + stateSize);
            sStep->registerMember(sMemberStep, stateSize);
        }
        void removeMember(const unsigned int& memberIndex) {
            std::copy(state.begin() + memberIndex + sStep->memberStateSizes[memberIndex], state.end(), state.begin() + memberIndex);
            state.conservativeResize(state.size() - sStep->memberStateSizes[memberIndex]);
            sStep->unregisterMember(memberIndex);
        }
        void updateMemberSize(const unsigned int& memberIndex, const unsigned int& stateSize) {
            const int difference = stateSize - sStep->memberStateSizes[memberIndex];
            if(difference > 0) {
                state.conservativeResize(state.size() + difference);
                std::copy(state.begin() + memberIndex + sStep->memberStateSizes[memberIndex], state.end() - difference, state.begin() + stateSize);
            } else {
                std::copy(state.begin() + memberIndex + sStep->memberStateSizes[memberIndex], state.end(), state.begin() + stateSize);
                state.conservativeResize(state.size() + difference);
            }
            sStep->updateMemberSize(memberIndex, difference);
        }
    public:
        // Inherited properties
        using Type::sSolver;
        using Type::sStep;
        using Type::state;
        using Type::t;
};

}

#endif
