#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_PAIR_AGENT_POSITION_B_CHOICE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_PAIR_AGENT_POSITION_B_CHOICE_H
#pragma once

// std includes
#include <memory> // shared_ptr
// module includes
#include "sl0/object.h"
// app includes
#include "core/env/objects/object/pair/agent_position_b/prop.h"

namespace c0p {

template<typename TypeParameters, typename TypeAStep_, typename TypeBStep_>
class PairAgentPositionBStep : public sl0::StepObjectStatic<TypeVector, DIM, TypeAStep_::StateSize + TypeBStep_::StateSize> {
	public:
		TypeParameters parameters;
	public:
		using TypeAStep = TypeAStep_;
		using TypeBStep = TypeBStep_;
	public:
		using Type = sl0::StepObjectStatic<TypeVector, DIM, TypeAStep::StateSize+TypeBStep::StateSize>;
		using Type::StateSize;
		using TypeStateVectorDynamic = typename Type::TypeStateVectorDynamic;
	public:
		PairAgentPositionBStep(const std::shared_ptr<Flow>& sFlow, std::shared_ptr<Objects> sObjects) : Type(), sAStep(std::make_shared<TypeAStep>(sFlow, sObjects)), sBStep(std::make_shared<TypeBStep>(sFlow, sObjects)) {

		}

		PairAgentPositionBStep(const PairAgentPositionBStep& step) : Type(step) {
   			sAStep = std::make_shared<TypeAStep>(*step.sAStep);
   			sBStep = std::make_shared<TypeBStep>(*step.sBStep);
   		}

		TypeStateVectorDynamic operator()(const double* pState, const double& t) const override {
			TypeStateVectorDynamic dState(Type::stateSize());
			// a
			TypeView<TypeStateVectorDynamic> dA(aState(dState.data()), TypeAStep::StateSize);
			dA = (*sAStep)(cAState(pState), t);
			// b
			TypeView<TypeStateVectorDynamic> dB(bState(dState.data()), TypeBStep::StateSize);
			dB = (*sBStep)(cBState(pState), t);
			// return
			return dState;
		}
		
		void update(double* pState, const double& t) override {
			sAStep->sBehaviour->sensorPosition.parameters.position = sBStep->cX(cBState(pState));
			sAStep->update(aState(pState), t);
			sBStep->update(bState(pState), t);
		}
	public:
		TypeContainer<TypeSpaceVector> positions(const double* pState) const override {
			TypeContainer<TypeSpaceVector> result;
			// sensors
			const TypeContainer<TypeSpaceVector> positionsA = sAStep->positions(cAState(pState));
			result.insert(result.end(), positionsA.begin(), positionsA.end());
			const TypeContainer<TypeSpaceVector> positionsB = sBStep->positions(cBState(pState));
			result.insert(result.end(), positionsB.begin(), positionsB.end());
			// return
			return result;
		}
	public:
		const double* cAState(const double* pState) const {
			return pState;
		}

		double* aState(double* pState) const {
			return pState;
		}

		const double* cBState(const double* pState) const {
			return pState + TypeAStep::StateSize;
		}

		double* bState(double* pState) const {
			return pState + TypeAStep::StateSize;
		}
	public:
		std::shared_ptr<TypeAStep> sAStep;
		std::shared_ptr<TypeBStep> sBStep;
};

}

#endif
