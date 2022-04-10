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
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_0o0__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_0o5__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_2o5__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_3o5__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_4o0__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_4o5__reorientationtime_0o5/choice.h"
#include "param/env/objects/static/surfer__us_15o58__surftimeconst_5o0__reorientationtime_0o5/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
	// FLAG: DECLARE OBJECT BEGIN
	std::shared_ptr<SurferUs15O58Surftimeconst1O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst1O0Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst0O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst0O0Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_0o0__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst0O5Reorientationtime0O5Step> sSurferUs15O58Surftimeconst0O5Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_0o5__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst1O5Reorientationtime0O5Step> sSurferUs15O58Surftimeconst1O5Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst2O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst2O0Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst2O5Reorientationtime0O5Step> sSurferUs15O58Surftimeconst2O5Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_2o5__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst3O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst3O0Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst3O5Reorientationtime0O5Step> sSurferUs15O58Surftimeconst3O5Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_3o5__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst4O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst4O0Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_4o0__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst4O5Reorientationtime0O5Step> sSurferUs15O58Surftimeconst4O5Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_4o5__reorientationtime_0o5Index;
	std::shared_ptr<SurferUs15O58Surftimeconst5O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst5O0Reorientationtime0O5Step;
	unsigned int surfer__us_15o58__surftimeconst_5o0__reorientationtime_0o5Index;
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
		// // surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5
		sSurferUs15O58Surftimeconst1O0Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst1O0Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst1O0Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_0o0__reorientationtime_0o5
		sSurferUs15O58Surftimeconst0O0Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst0O0Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst0O0Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_0o0__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_0o0__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_0o5__reorientationtime_0o5
		sSurferUs15O58Surftimeconst0O5Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst0O5Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst0O5Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_0o5__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_0o5__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5
		sSurferUs15O58Surftimeconst1O5Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst1O5Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst1O5Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_1o5__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5
		sSurferUs15O58Surftimeconst2O0Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst2O0Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst2O0Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_2o5__reorientationtime_0o5
		sSurferUs15O58Surftimeconst2O5Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst2O5Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst2O5Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_2o5__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_2o5__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5
		sSurferUs15O58Surftimeconst3O0Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst3O0Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst3O0Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_3o0__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_3o5__reorientationtime_0o5
		sSurferUs15O58Surftimeconst3O5Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst3O5Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst3O5Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_3o5__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_3o5__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_4o0__reorientationtime_0o5
		sSurferUs15O58Surftimeconst4O0Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst4O0Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst4O0Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_4o0__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_4o0__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_4o5__reorientationtime_0o5
		sSurferUs15O58Surftimeconst4O5Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst4O5Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst4O5Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_4o5__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_4o5__reorientationtime_0o5");
		// // surfer__us_15o58__surftimeconst_5o0__reorientationtime_0o5
		sSurferUs15O58Surftimeconst5O0Reorientationtime0O5Step = std::make_shared<SurferUs15O58Surftimeconst5O0Reorientationtime0O5Step>(sFlow, sObjects);
		sObjectsStaticSteps.push_back(sSurferUs15O58Surftimeconst5O0Reorientationtime0O5Step);
		surfer__us_15o58__surftimeconst_5o0__reorientationtime_0o5Index = sObjectsStaticSteps.size() - 1;
		objectsStaticNames.push_back("surfer__us_15o58__surftimeconst_5o0__reorientationtime_0o5");
		// FLAG: MAKE OBJECT END
	}
};

}

#endif
