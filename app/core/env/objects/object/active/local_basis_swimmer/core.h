#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_BASIS_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_BASIS_SWIMMER_CORE_H
#pragma once

// std includes
#include <memory>
// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/active/local_basis_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename ActivePassiveStep>
class ActiveLocalBasisSwimmerStep : public TypeActiveStep<ActivePassiveStep>  {
	public:
		using Type = TypeActiveStep<ActivePassiveStep>;
		using TypeStateVectorDynamic = typename Type::TypeStateVectorDynamic;
	public:
		TypeParameters parameters;
		std::shared_ptr<TypeLocalBasisSwimStep<ActivePassiveStep>> sStepLocalBasisSwim;
		std::shared_ptr<TypeBasisOrientStep<ActivePassiveStep>> sStepBasisOrient;
	public:
		ActiveLocalBasisSwimmerStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : 
			Type(ActivePassiveStep(sFlow, sObjects)), 
			sStepLocalBasisSwim(std::make_shared<TypeLocalBasisSwimStep<ActivePassiveStep>>(parameters.velocity, parameters.swimAxis)),
			sStepBasisOrient(std::make_shared<TypeBasisOrientStep<ActivePassiveStep>>(parameters.direction, parameters.time, parameters.alignAxis))
		{
			Type::registerActuator(sStepLocalBasisSwim);
			Type::registerActuator(sStepBasisOrient);
		}

		ActiveLocalBasisSwimmerStep(const ActiveLocalBasisSwimmerStep& step) : Type(step)
		{
			Type::clearActuators();
			sStepLocalBasisSwim = std::make_shared<TypeLocalBasisSwimStep<ActivePassiveStep>>(parameters.velocity, parameters.swimAxis);
			sStepBasisOrient = std::make_shared<TypeBasisOrientStep<ActivePassiveStep>>(parameters.direction, parameters.time, parameters.alignAxis);
			Type::registerActuator(sStepLocalBasisSwim);
			Type::registerActuator(sStepBasisOrient);
		}
};

}

#endif
