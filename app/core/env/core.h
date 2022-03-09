#ifndef C0P_CORE_ENV_CORE_H
#define C0P_CORE_ENV_CORE_H
#pragma once

// std includes
#include <memory>
#include <map>
// lib includes
#include "s0ve/double.h"
#include "l0ad/ascii/double.h"
// app includes
#include "core/env/prop.h"
#include "param/env/flow/choice.h"
#include "core/env/objects/core.h"
#include "param/env/objects/parameters.h"

namespace c0p {

template<typename Parameters>
class Env {
	public:
		Parameters parameters;
		std::shared_ptr<Flow> sFlow;
		std::shared_ptr<Objects> sObjects;
		std::shared_ptr<ObjectsParameters> sObjectsParameters;

		Env() : parameters() {
			// create properties
			sFlow = std::make_shared<Flow>();
			sObjects = std::make_shared<Objects>(sFlow);
			sObjectsParameters = std::make_shared<ObjectsParameters>(sFlow, sObjects);
			// add objects
			for(std::shared_ptr<StepObjectStatic> sStaticStep : sObjectsParameters->sObjectsStaticSteps) {
				sObjects->sStepStatic->addMember(sObjects->stateStatic, sStaticStep, sStaticStep->stateSize());
			}
			for(std::shared_ptr<StepObjectDynamic> sDynamicStep : sObjectsParameters->sObjectsDynamicSteps) {
				sObjects->addDynamicObject(sDynamicStep);
			}
			for(std::shared_ptr<StepObjectManager> sManagerStep : sObjectsParameters->sObjectsManagerSteps) {
				sObjects->addObjectManager(sManagerStep);
			}
		}
};

}

#endif
