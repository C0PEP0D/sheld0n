#ifndef C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_AXIS_SWIMMER_CORE_H
#define C0P_CORE_ENV_OBJECTS_OBJECT_ACTIVE_LOCAL_AXIS_SWIMMER_CORE_H
#pragma once

// std includes
#include <memory>
// app includes
#include "core/env/objects/core.h"
#include "core/env/objects/object/active/local_axis_swimmer/prop.h"

namespace c0p {

template<typename TypeParameters, typename ActivePassiveStep>
class ActiveLocalAxisSwimmerStep : public TypeActiveStep<ActivePassiveStep>  {
	public:
		using Type = TypeActiveStep<ActivePassiveStep>;
		using TypeStateVectorDynamic = typename Type::TypeStateVectorDynamic;
	public:
		TypeParameters parameters;
		std::shared_ptr<TypeLocalAxisSwimStep<ActivePassiveStep>> sStepLocalAxisSwim;
		std::shared_ptr<TypeAxisOrientStep<ActivePassiveStep>> sStepAxisOrient;
	public:
		ActiveLocalAxisSwimmerStep(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) : 
			Type(ActivePassiveStep(sFlow, sObjects)), 
			sStepLocalAxisSwim(std::make_shared<TypeLocalAxisSwimStep<ActivePassiveStep>>(parameters.velocity)),
			sStepAxisOrient(std::make_shared<TypeAxisOrientStep<ActivePassiveStep>>(parameters.direction, parameters.time))
		{
			Type::registerActuator(sStepLocalAxisSwim);
			Type::registerActuator(sStepAxisOrient);
		}

		ActiveLocalAxisSwimmerStep(const ActiveLocalAxisSwimmerStep& step) : Type(step)
		{
			Type::clearActuators();
			sStepLocalAxisSwim = std::make_shared<TypeLocalAxisSwimStep<ActivePassiveStep>>(parameters.velocity);
			sStepAxisOrient = std::make_shared<TypeAxisOrientStep<ActivePassiveStep>>(parameters.direction, parameters.time);
			Type::registerActuator(sStepLocalAxisSwim);
			Type::registerActuator(sStepAxisOrient);
		}
};

}

#endif
