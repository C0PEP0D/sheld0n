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
#include "param/env/objects/static/object/choice.h"
#include "param/env/objects/dynamic/dobject/choice.h"
#include "param/env/objects/manager/mobject/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
	// FLAG: DECLARE OBJECT BEGIN
	std::shared_ptr<ObjectStep> sObjectStep;
	unsigned int objectIndex;
	std::shared_ptr<DobjectStep> sDobjectStep;
	unsigned int dobjectIndex;
	std::shared_ptr<MobjectStep> sMobjectStep;
	unsigned int mobjectIndex;
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
		// // object
		sObjectStep = std::make_shared<ObjectStep>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sObjectStep);
		objectIndex = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("object");
		// // dobject
		sDobjectStep = std::make_shared<DobjectStep>(sFlow, sObjects);
		sObjectsDynamicSteps.push_back(sDobjectStep);
		dobjectIndex = sObjectsDynamicSteps.size() - 1;
		objectsDynamicNames.push_back("dobject");
		// // mobject
		sMobjectStep = std::make_shared<MobjectStep>(sFlow, sObjects);
		sObjectsManagerSteps.push_back(sMobjectStep);
		mobjectIndex = sObjectsManagerSteps.size() - 1;
		objectsManagerNames.push_back("mobject");
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
