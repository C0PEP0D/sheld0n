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
#include "param/env/objects/static/tracers__e3_1o0/choice.h"
#include "param/env/objects/static/tracers__e3_0o01/choice.h"
#include "param/env/objects/static/tracers__e3_0o1/choice.h"
#include "param/env/objects/static/tracers__e3_10o0/choice.h"
#include "param/env/objects/static/tracers__e1_0o01/choice.h"
#include "param/env/objects/static/tracers__e1_0o1/choice.h"
#include "param/env/objects/static/tracers__e1_1o0/choice.h"
#include "param/env/objects/static/tracers__e1_10o0/choice.h"
#include "param/env/objects/static/tracers__e2_0o01/choice.h"
#include "param/env/objects/static/tracers__e2_0o1/choice.h"
#include "param/env/objects/static/tracers__e2_1o0/choice.h"
#include "param/env/objects/static/tracers__e2_10o0/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
	// FLAG: DECLARE OBJECT BEGIN
	std::shared_ptr<TracersE31O0Step> sTracersE31O0Step;
	unsigned int tracers__e3_1o0Index;
	std::shared_ptr<TracersE30O01Step> sTracersE30O01Step;
	unsigned int tracers__e3_0o01Index;
	std::shared_ptr<TracersE30O1Step> sTracersE30O1Step;
	unsigned int tracers__e3_0o1Index;
	std::shared_ptr<TracersE310O0Step> sTracersE310O0Step;
	unsigned int tracers__e3_10o0Index;
	std::shared_ptr<TracersE10O01Step> sTracersE10O01Step;
	unsigned int tracers__e1_0o01Index;
	std::shared_ptr<TracersE10O1Step> sTracersE10O1Step;
	unsigned int tracers__e1_0o1Index;
	std::shared_ptr<TracersE11O0Step> sTracersE11O0Step;
	unsigned int tracers__e1_1o0Index;
	std::shared_ptr<TracersE110O0Step> sTracersE110O0Step;
	unsigned int tracers__e1_10o0Index;
	std::shared_ptr<TracersE20O01Step> sTracersE20O01Step;
	unsigned int tracers__e2_0o01Index;
	std::shared_ptr<TracersE20O1Step> sTracersE20O1Step;
	unsigned int tracers__e2_0o1Index;
	std::shared_ptr<TracersE21O0Step> sTracersE21O0Step;
	unsigned int tracers__e2_1o0Index;
	std::shared_ptr<TracersE210O0Step> sTracersE210O0Step;
	unsigned int tracers__e2_10o0Index;
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
		// // tracers__e3_1o0
		sTracersE31O0Step = std::make_shared<TracersE31O0Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE31O0Step);
		tracers__e3_1o0Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e3_1o0");
		// // tracers__e3_0o01
		sTracersE30O01Step = std::make_shared<TracersE30O01Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE30O01Step);
		tracers__e3_0o01Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e3_0o01");
		// // tracers__e3_0o1
		sTracersE30O1Step = std::make_shared<TracersE30O1Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE30O1Step);
		tracers__e3_0o1Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e3_0o1");
		// // tracers__e3_10o0
		sTracersE310O0Step = std::make_shared<TracersE310O0Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE310O0Step);
		tracers__e3_10o0Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e3_10o0");
		// // tracers__e1_0o01
		sTracersE10O01Step = std::make_shared<TracersE10O01Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE10O01Step);
		tracers__e1_0o01Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e1_0o01");
		// // tracers__e1_0o1
		sTracersE10O1Step = std::make_shared<TracersE10O1Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE10O1Step);
		tracers__e1_0o1Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e1_0o1");
		// // tracers__e1_1o0
		sTracersE11O0Step = std::make_shared<TracersE11O0Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE11O0Step);
		tracers__e1_1o0Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e1_1o0");
		// // tracers__e1_10o0
		sTracersE110O0Step = std::make_shared<TracersE110O0Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE110O0Step);
		tracers__e1_10o0Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e1_10o0");
		// // tracers__e2_0o01
		sTracersE20O01Step = std::make_shared<TracersE20O01Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE20O01Step);
		tracers__e2_0o01Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e2_0o01");
		// // tracers__e2_0o1
		sTracersE20O1Step = std::make_shared<TracersE20O1Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE20O1Step);
		tracers__e2_0o1Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e2_0o1");
		// // tracers__e2_1o0
		sTracersE21O0Step = std::make_shared<TracersE21O0Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE21O0Step);
		tracers__e2_1o0Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e2_1o0");
		// // tracers__e2_10o0
		sTracersE210O0Step = std::make_shared<TracersE210O0Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sTracersE210O0Step);
		tracers__e2_10o0Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("tracers__e2_10o0");
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
