#ifndef C0P_PARAM_ENV_OBJECTS_PARAMETERS_H
#define C0P_PARAM_ENV_OBJECTS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std includes
#include <memory> // shared_ptr
#include <vector>
#include <string>
// app includes
#include "core/env/objects/prop.h"
#include "core/env/objects/core.h"
#include "param/env/flow/choice.h"
// FLAG: INCLUDE OBJECT BEGIN
#include "param/env/objects/static/tracer/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
	// FLAG: DECLARE OBJECT BEGIN
	std::shared_ptr<TracerStep> sTracerStep;
	unsigned int tracerIndex;
	// FLAG: DECLARE OBJECT END
	
	// construct data
	std::vector<std::string> objectsStaticNames;
	std::vector<std::shared_ptr<StepObjectStatic>> sObjectsStaticSteps;
	std::vector<std::string> objectsDynamicNames;
	std::vector<std::shared_ptr<StepObjectDynamic>> sObjectsDynamicSteps;
	std::vector<std::string> objectsManagerNames;
	std::vector<std::shared_ptr<StepObjectManager>> sObjectsManagerSteps;
	ObjectsParameters(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) {
		// FLAG: MAKE OBJECT BEGIN
		// // tracer
		sTracerStep = std::make_shared<TracerStep>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracerStep);
		tracerIndex = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracer");
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
