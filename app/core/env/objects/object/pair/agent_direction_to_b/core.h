#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PAIR_AGENT_DIRECTION_TO_B_CHOICE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PAIR_AGENT_DIRECTION_TO_B_CHOICE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// module includes
#include "sl0/object.h"
// app includes
#include "core/env/objects/object/pair/agent_direction_to_b/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeAStep_, typename TypeBStep_>
class PairAgentDirectionToBStep : public sl0::StepObjectStatic<TypeVector, TypeRef, TypeAStep_::StateSize + TypeBStep_::StateSize> {
    public:
        TypeParameters parameters;
    public:
        using TypeAStep = TypeAStep_;
        using TypeBStep = TypeBStep_;
    public:
        using Type = sl0::StepObjectStatic<TypeVector, TypeRef, TypeAStep::StateSize+TypeBStep::StateSize>;
        using Type::StateSize;
        using typename Type::TypeStateStatic;
    public:
        PairAgentDirectionToBStep(const std::shared_ptr<Flow>& sFlow) : Type(), sAStep(std::make_shared<TypeAStep>(sFlow)), sBStep(std::make_shared<TypeBStep>(sFlow)) {

        }

        TypeStateStatic operator()(const TypeRef<const TypeStateStatic>& state, const double& t) const override {
            TypeStateStatic dState;
            // a
            TypeView<typename TypeAStep::TypeStateStatic> dA = aState(dState);
            dA = (*sAStep)(cAState(state), t);
            // b
            TypeView<typename TypeBStep::TypeStateStatic> dB = bState(dState);
            dB = (*sBStep)(cBState(state), t);
            // return
            return dState;
        }
        
        void update(TypeRef<TypeStateStatic> state, const double& t) override {
            sAStep->sBehaviour->direction.parameters.direction = (sBStep->cX(cBState(state)) - sAStep->cX(cAState(state))).normalized();
            sAStep->update(TypeRef<typename TypeAStep::TypeStateStatic>(aState(state)), t);
            sBStep->update(TypeRef<typename TypeBStep::TypeStateStatic>(bState(state)), t);
        }
    public:
        TypeView<const typename TypeAStep::TypeStateStatic> cAState(const TypeRef<const TypeStateStatic>& state) const {
            return TypeView<const typename TypeAStep::TypeStateStatic>(state.data());
        }

        TypeView<typename TypeAStep::TypeStateStatic> aState(TypeRef<TypeStateStatic> state) const {
            return TypeView<typename TypeAStep::TypeStateStatic>(state.data());
        }

        TypeView<const typename TypeBStep::TypeStateStatic> cBState(const TypeRef<const TypeStateStatic>& state) const {
            return TypeView<const typename TypeBStep::TypeStateStatic>(state.data() + TypeAStep::StateSize);
        }

        TypeView<typename TypeBStep::TypeStateStatic> bState(TypeRef<TypeStateStatic> state) const {
            return TypeView<typename TypeBStep::TypeStateStatic>(state.data() + TypeAStep::StateSize);
        }
    public:
        std::shared_ptr<TypeAStep> sAStep;
        std::shared_ptr<TypeBStep> sBStep;
};

}

#endif
