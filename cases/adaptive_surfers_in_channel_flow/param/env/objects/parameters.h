#ifndef C0P_PARAM_ENV_OBJECTS_PARAMETERS_H
#define C0P_PARAM_ENV_OBJECTS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std includes
#include <memory>
// app includes
#include "core/env/objects/prop.h"
#include "core/env/objects/core.h"
#include "param/env/flow/choice.h"
// FLAG: INCLUDE OBJECT BEGIN
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_1o0/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_1o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_1o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_0o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_0o25/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_0o5/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_0o75/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_1o25/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_1o5/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_1o75/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_2o0/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_2o25/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_2o5/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_2o75/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_3o0/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_0o0/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_0o25/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_0o5/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_0o75/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_1o25/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_1o5/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_1o75/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_2o0/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_2o25/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_2o5/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_2o75/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_3o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_0o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_0o25/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_0o5/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_0o75/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_1o25/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_1o5/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_1o75/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o0/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o25/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o5/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o75/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_3o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_0o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_0o25/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_0o5/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_0o75/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o25/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o5/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o75/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_2o0/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_2o25/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_2o5/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_2o75/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_3o0/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
    // FLAG: DECLARE OBJECT BEGIN
    std::shared_ptr<SurferUs1O0Surftimeprefactor1O0Step> sSurferUs1O0Surftimeprefactor1O0Step;
    unsigned int surfer__us_1o0__surftimeprefactor_1o0Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor1O0Step> sSurferUs0O1Surftimeprefactor1O0Step;
    unsigned int surfer__us_0o1__surftimeprefactor_1o0Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor1O0Step> sSurferUs0O5Surftimeprefactor1O0Step;
    unsigned int surfer__us_0o5__surftimeprefactor_1o0Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor1O0Step> sSurferUs2O0Surftimeprefactor1O0Step;
    unsigned int surfer__us_2o0__surftimeprefactor_1o0Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor0O0Step> sSurferUs1O0Surftimeprefactor0O0Step;
    unsigned int surfer__us_1o0__surftimeprefactor_0o0Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor0O25Step> sSurferUs1O0Surftimeprefactor0O25Step;
    unsigned int surfer__us_1o0__surftimeprefactor_0o25Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor0O5Step> sSurferUs1O0Surftimeprefactor0O5Step;
    unsigned int surfer__us_1o0__surftimeprefactor_0o5Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor0O75Step> sSurferUs1O0Surftimeprefactor0O75Step;
    unsigned int surfer__us_1o0__surftimeprefactor_0o75Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor1O25Step> sSurferUs1O0Surftimeprefactor1O25Step;
    unsigned int surfer__us_1o0__surftimeprefactor_1o25Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor1O5Step> sSurferUs1O0Surftimeprefactor1O5Step;
    unsigned int surfer__us_1o0__surftimeprefactor_1o5Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor1O75Step> sSurferUs1O0Surftimeprefactor1O75Step;
    unsigned int surfer__us_1o0__surftimeprefactor_1o75Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor2O0Step> sSurferUs1O0Surftimeprefactor2O0Step;
    unsigned int surfer__us_1o0__surftimeprefactor_2o0Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor2O25Step> sSurferUs1O0Surftimeprefactor2O25Step;
    unsigned int surfer__us_1o0__surftimeprefactor_2o25Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor2O5Step> sSurferUs1O0Surftimeprefactor2O5Step;
    unsigned int surfer__us_1o0__surftimeprefactor_2o5Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor2O75Step> sSurferUs1O0Surftimeprefactor2O75Step;
    unsigned int surfer__us_1o0__surftimeprefactor_2o75Index;
    std::shared_ptr<SurferUs1O0Surftimeprefactor3O0Step> sSurferUs1O0Surftimeprefactor3O0Step;
    unsigned int surfer__us_1o0__surftimeprefactor_3o0Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor0O0Step> sSurferUs0O1Surftimeprefactor0O0Step;
    unsigned int surfer__us_0o1__surftimeprefactor_0o0Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor0O25Step> sSurferUs0O1Surftimeprefactor0O25Step;
    unsigned int surfer__us_0o1__surftimeprefactor_0o25Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor0O5Step> sSurferUs0O1Surftimeprefactor0O5Step;
    unsigned int surfer__us_0o1__surftimeprefactor_0o5Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor0O75Step> sSurferUs0O1Surftimeprefactor0O75Step;
    unsigned int surfer__us_0o1__surftimeprefactor_0o75Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor1O25Step> sSurferUs0O1Surftimeprefactor1O25Step;
    unsigned int surfer__us_0o1__surftimeprefactor_1o25Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor1O5Step> sSurferUs0O1Surftimeprefactor1O5Step;
    unsigned int surfer__us_0o1__surftimeprefactor_1o5Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor1O75Step> sSurferUs0O1Surftimeprefactor1O75Step;
    unsigned int surfer__us_0o1__surftimeprefactor_1o75Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor2O0Step> sSurferUs0O1Surftimeprefactor2O0Step;
    unsigned int surfer__us_0o1__surftimeprefactor_2o0Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor2O25Step> sSurferUs0O1Surftimeprefactor2O25Step;
    unsigned int surfer__us_0o1__surftimeprefactor_2o25Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor2O5Step> sSurferUs0O1Surftimeprefactor2O5Step;
    unsigned int surfer__us_0o1__surftimeprefactor_2o5Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor2O75Step> sSurferUs0O1Surftimeprefactor2O75Step;
    unsigned int surfer__us_0o1__surftimeprefactor_2o75Index;
    std::shared_ptr<SurferUs0O1Surftimeprefactor3O0Step> sSurferUs0O1Surftimeprefactor3O0Step;
    unsigned int surfer__us_0o1__surftimeprefactor_3o0Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor0O0Step> sSurferUs0O5Surftimeprefactor0O0Step;
    unsigned int surfer__us_0o5__surftimeprefactor_0o0Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor0O25Step> sSurferUs0O5Surftimeprefactor0O25Step;
    unsigned int surfer__us_0o5__surftimeprefactor_0o25Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor0O5Step> sSurferUs0O5Surftimeprefactor0O5Step;
    unsigned int surfer__us_0o5__surftimeprefactor_0o5Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor0O75Step> sSurferUs0O5Surftimeprefactor0O75Step;
    unsigned int surfer__us_0o5__surftimeprefactor_0o75Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor1O25Step> sSurferUs0O5Surftimeprefactor1O25Step;
    unsigned int surfer__us_0o5__surftimeprefactor_1o25Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor1O5Step> sSurferUs0O5Surftimeprefactor1O5Step;
    unsigned int surfer__us_0o5__surftimeprefactor_1o5Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor1O75Step> sSurferUs0O5Surftimeprefactor1O75Step;
    unsigned int surfer__us_0o5__surftimeprefactor_1o75Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor2O0Step> sSurferUs0O5Surftimeprefactor2O0Step;
    unsigned int surfer__us_0o5__surftimeprefactor_2o0Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor2O25Step> sSurferUs0O5Surftimeprefactor2O25Step;
    unsigned int surfer__us_0o5__surftimeprefactor_2o25Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor2O5Step> sSurferUs0O5Surftimeprefactor2O5Step;
    unsigned int surfer__us_0o5__surftimeprefactor_2o5Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor2O75Step> sSurferUs0O5Surftimeprefactor2O75Step;
    unsigned int surfer__us_0o5__surftimeprefactor_2o75Index;
    std::shared_ptr<SurferUs0O5Surftimeprefactor3O0Step> sSurferUs0O5Surftimeprefactor3O0Step;
    unsigned int surfer__us_0o5__surftimeprefactor_3o0Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor0O0Step> sSurferUs2O0Surftimeprefactor0O0Step;
    unsigned int surfer__us_2o0__surftimeprefactor_0o0Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor0O25Step> sSurferUs2O0Surftimeprefactor0O25Step;
    unsigned int surfer__us_2o0__surftimeprefactor_0o25Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor0O5Step> sSurferUs2O0Surftimeprefactor0O5Step;
    unsigned int surfer__us_2o0__surftimeprefactor_0o5Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor0O75Step> sSurferUs2O0Surftimeprefactor0O75Step;
    unsigned int surfer__us_2o0__surftimeprefactor_0o75Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor1O25Step> sSurferUs2O0Surftimeprefactor1O25Step;
    unsigned int surfer__us_2o0__surftimeprefactor_1o25Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor1O5Step> sSurferUs2O0Surftimeprefactor1O5Step;
    unsigned int surfer__us_2o0__surftimeprefactor_1o5Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor1O75Step> sSurferUs2O0Surftimeprefactor1O75Step;
    unsigned int surfer__us_2o0__surftimeprefactor_1o75Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor2O0Step> sSurferUs2O0Surftimeprefactor2O0Step;
    unsigned int surfer__us_2o0__surftimeprefactor_2o0Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor2O25Step> sSurferUs2O0Surftimeprefactor2O25Step;
    unsigned int surfer__us_2o0__surftimeprefactor_2o25Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor2O5Step> sSurferUs2O0Surftimeprefactor2O5Step;
    unsigned int surfer__us_2o0__surftimeprefactor_2o5Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor2O75Step> sSurferUs2O0Surftimeprefactor2O75Step;
    unsigned int surfer__us_2o0__surftimeprefactor_2o75Index;
    std::shared_ptr<SurferUs2O0Surftimeprefactor3O0Step> sSurferUs2O0Surftimeprefactor3O0Step;
    unsigned int surfer__us_2o0__surftimeprefactor_3o0Index;
    // FLAG: DECLARE OBJECT END
    
    // construct data
    std::vector<std::shared_ptr<StepObjectStatic>> sObjectsStaticSteps;
    std::vector<std::shared_ptr<StepObjectDynamic>> sObjectsDynamicSteps;
    ObjectsParameters(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) {
        // FLAG: MAKE OBJECT BEGIN
        // // surfer__us_1o0__surftimeprefactor_1o0
        sSurferUs1O0Surftimeprefactor1O0Step = std::make_shared<SurferUs1O0Surftimeprefactor1O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor1O0Step);
        surfer__us_1o0__surftimeprefactor_1o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_1o0
        sSurferUs0O1Surftimeprefactor1O0Step = std::make_shared<SurferUs0O1Surftimeprefactor1O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor1O0Step);
        surfer__us_0o1__surftimeprefactor_1o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_1o0
        sSurferUs0O5Surftimeprefactor1O0Step = std::make_shared<SurferUs0O5Surftimeprefactor1O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor1O0Step);
        surfer__us_0o5__surftimeprefactor_1o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_1o0
        sSurferUs2O0Surftimeprefactor1O0Step = std::make_shared<SurferUs2O0Surftimeprefactor1O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor1O0Step);
        surfer__us_2o0__surftimeprefactor_1o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_0o0
        sSurferUs1O0Surftimeprefactor0O0Step = std::make_shared<SurferUs1O0Surftimeprefactor0O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor0O0Step);
        surfer__us_1o0__surftimeprefactor_0o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_0o25
        sSurferUs1O0Surftimeprefactor0O25Step = std::make_shared<SurferUs1O0Surftimeprefactor0O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor0O25Step);
        surfer__us_1o0__surftimeprefactor_0o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_0o5
        sSurferUs1O0Surftimeprefactor0O5Step = std::make_shared<SurferUs1O0Surftimeprefactor0O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor0O5Step);
        surfer__us_1o0__surftimeprefactor_0o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_0o75
        sSurferUs1O0Surftimeprefactor0O75Step = std::make_shared<SurferUs1O0Surftimeprefactor0O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor0O75Step);
        surfer__us_1o0__surftimeprefactor_0o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_1o25
        sSurferUs1O0Surftimeprefactor1O25Step = std::make_shared<SurferUs1O0Surftimeprefactor1O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor1O25Step);
        surfer__us_1o0__surftimeprefactor_1o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_1o5
        sSurferUs1O0Surftimeprefactor1O5Step = std::make_shared<SurferUs1O0Surftimeprefactor1O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor1O5Step);
        surfer__us_1o0__surftimeprefactor_1o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_1o75
        sSurferUs1O0Surftimeprefactor1O75Step = std::make_shared<SurferUs1O0Surftimeprefactor1O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor1O75Step);
        surfer__us_1o0__surftimeprefactor_1o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_2o0
        sSurferUs1O0Surftimeprefactor2O0Step = std::make_shared<SurferUs1O0Surftimeprefactor2O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor2O0Step);
        surfer__us_1o0__surftimeprefactor_2o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_2o25
        sSurferUs1O0Surftimeprefactor2O25Step = std::make_shared<SurferUs1O0Surftimeprefactor2O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor2O25Step);
        surfer__us_1o0__surftimeprefactor_2o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_2o5
        sSurferUs1O0Surftimeprefactor2O5Step = std::make_shared<SurferUs1O0Surftimeprefactor2O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor2O5Step);
        surfer__us_1o0__surftimeprefactor_2o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_2o75
        sSurferUs1O0Surftimeprefactor2O75Step = std::make_shared<SurferUs1O0Surftimeprefactor2O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor2O75Step);
        surfer__us_1o0__surftimeprefactor_2o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_1o0__surftimeprefactor_3o0
        sSurferUs1O0Surftimeprefactor3O0Step = std::make_shared<SurferUs1O0Surftimeprefactor3O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs1O0Surftimeprefactor3O0Step);
        surfer__us_1o0__surftimeprefactor_3o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_0o0
        sSurferUs0O1Surftimeprefactor0O0Step = std::make_shared<SurferUs0O1Surftimeprefactor0O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor0O0Step);
        surfer__us_0o1__surftimeprefactor_0o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_0o25
        sSurferUs0O1Surftimeprefactor0O25Step = std::make_shared<SurferUs0O1Surftimeprefactor0O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor0O25Step);
        surfer__us_0o1__surftimeprefactor_0o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_0o5
        sSurferUs0O1Surftimeprefactor0O5Step = std::make_shared<SurferUs0O1Surftimeprefactor0O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor0O5Step);
        surfer__us_0o1__surftimeprefactor_0o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_0o75
        sSurferUs0O1Surftimeprefactor0O75Step = std::make_shared<SurferUs0O1Surftimeprefactor0O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor0O75Step);
        surfer__us_0o1__surftimeprefactor_0o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_1o25
        sSurferUs0O1Surftimeprefactor1O25Step = std::make_shared<SurferUs0O1Surftimeprefactor1O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor1O25Step);
        surfer__us_0o1__surftimeprefactor_1o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_1o5
        sSurferUs0O1Surftimeprefactor1O5Step = std::make_shared<SurferUs0O1Surftimeprefactor1O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor1O5Step);
        surfer__us_0o1__surftimeprefactor_1o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_1o75
        sSurferUs0O1Surftimeprefactor1O75Step = std::make_shared<SurferUs0O1Surftimeprefactor1O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor1O75Step);
        surfer__us_0o1__surftimeprefactor_1o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_2o0
        sSurferUs0O1Surftimeprefactor2O0Step = std::make_shared<SurferUs0O1Surftimeprefactor2O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor2O0Step);
        surfer__us_0o1__surftimeprefactor_2o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_2o25
        sSurferUs0O1Surftimeprefactor2O25Step = std::make_shared<SurferUs0O1Surftimeprefactor2O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor2O25Step);
        surfer__us_0o1__surftimeprefactor_2o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_2o5
        sSurferUs0O1Surftimeprefactor2O5Step = std::make_shared<SurferUs0O1Surftimeprefactor2O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor2O5Step);
        surfer__us_0o1__surftimeprefactor_2o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_2o75
        sSurferUs0O1Surftimeprefactor2O75Step = std::make_shared<SurferUs0O1Surftimeprefactor2O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor2O75Step);
        surfer__us_0o1__surftimeprefactor_2o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o1__surftimeprefactor_3o0
        sSurferUs0O1Surftimeprefactor3O0Step = std::make_shared<SurferUs0O1Surftimeprefactor3O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O1Surftimeprefactor3O0Step);
        surfer__us_0o1__surftimeprefactor_3o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_0o0
        sSurferUs0O5Surftimeprefactor0O0Step = std::make_shared<SurferUs0O5Surftimeprefactor0O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor0O0Step);
        surfer__us_0o5__surftimeprefactor_0o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_0o25
        sSurferUs0O5Surftimeprefactor0O25Step = std::make_shared<SurferUs0O5Surftimeprefactor0O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor0O25Step);
        surfer__us_0o5__surftimeprefactor_0o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_0o5
        sSurferUs0O5Surftimeprefactor0O5Step = std::make_shared<SurferUs0O5Surftimeprefactor0O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor0O5Step);
        surfer__us_0o5__surftimeprefactor_0o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_0o75
        sSurferUs0O5Surftimeprefactor0O75Step = std::make_shared<SurferUs0O5Surftimeprefactor0O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor0O75Step);
        surfer__us_0o5__surftimeprefactor_0o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_1o25
        sSurferUs0O5Surftimeprefactor1O25Step = std::make_shared<SurferUs0O5Surftimeprefactor1O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor1O25Step);
        surfer__us_0o5__surftimeprefactor_1o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_1o5
        sSurferUs0O5Surftimeprefactor1O5Step = std::make_shared<SurferUs0O5Surftimeprefactor1O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor1O5Step);
        surfer__us_0o5__surftimeprefactor_1o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_1o75
        sSurferUs0O5Surftimeprefactor1O75Step = std::make_shared<SurferUs0O5Surftimeprefactor1O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor1O75Step);
        surfer__us_0o5__surftimeprefactor_1o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_2o0
        sSurferUs0O5Surftimeprefactor2O0Step = std::make_shared<SurferUs0O5Surftimeprefactor2O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor2O0Step);
        surfer__us_0o5__surftimeprefactor_2o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_2o25
        sSurferUs0O5Surftimeprefactor2O25Step = std::make_shared<SurferUs0O5Surftimeprefactor2O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor2O25Step);
        surfer__us_0o5__surftimeprefactor_2o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_2o5
        sSurferUs0O5Surftimeprefactor2O5Step = std::make_shared<SurferUs0O5Surftimeprefactor2O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor2O5Step);
        surfer__us_0o5__surftimeprefactor_2o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_2o75
        sSurferUs0O5Surftimeprefactor2O75Step = std::make_shared<SurferUs0O5Surftimeprefactor2O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor2O75Step);
        surfer__us_0o5__surftimeprefactor_2o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_0o5__surftimeprefactor_3o0
        sSurferUs0O5Surftimeprefactor3O0Step = std::make_shared<SurferUs0O5Surftimeprefactor3O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs0O5Surftimeprefactor3O0Step);
        surfer__us_0o5__surftimeprefactor_3o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_0o0
        sSurferUs2O0Surftimeprefactor0O0Step = std::make_shared<SurferUs2O0Surftimeprefactor0O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor0O0Step);
        surfer__us_2o0__surftimeprefactor_0o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_0o25
        sSurferUs2O0Surftimeprefactor0O25Step = std::make_shared<SurferUs2O0Surftimeprefactor0O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor0O25Step);
        surfer__us_2o0__surftimeprefactor_0o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_0o5
        sSurferUs2O0Surftimeprefactor0O5Step = std::make_shared<SurferUs2O0Surftimeprefactor0O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor0O5Step);
        surfer__us_2o0__surftimeprefactor_0o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_0o75
        sSurferUs2O0Surftimeprefactor0O75Step = std::make_shared<SurferUs2O0Surftimeprefactor0O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor0O75Step);
        surfer__us_2o0__surftimeprefactor_0o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_1o25
        sSurferUs2O0Surftimeprefactor1O25Step = std::make_shared<SurferUs2O0Surftimeprefactor1O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor1O25Step);
        surfer__us_2o0__surftimeprefactor_1o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_1o5
        sSurferUs2O0Surftimeprefactor1O5Step = std::make_shared<SurferUs2O0Surftimeprefactor1O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor1O5Step);
        surfer__us_2o0__surftimeprefactor_1o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_1o75
        sSurferUs2O0Surftimeprefactor1O75Step = std::make_shared<SurferUs2O0Surftimeprefactor1O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor1O75Step);
        surfer__us_2o0__surftimeprefactor_1o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_2o0
        sSurferUs2O0Surftimeprefactor2O0Step = std::make_shared<SurferUs2O0Surftimeprefactor2O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor2O0Step);
        surfer__us_2o0__surftimeprefactor_2o0Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_2o25
        sSurferUs2O0Surftimeprefactor2O25Step = std::make_shared<SurferUs2O0Surftimeprefactor2O25Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor2O25Step);
        surfer__us_2o0__surftimeprefactor_2o25Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_2o5
        sSurferUs2O0Surftimeprefactor2O5Step = std::make_shared<SurferUs2O0Surftimeprefactor2O5Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor2O5Step);
        surfer__us_2o0__surftimeprefactor_2o5Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_2o75
        sSurferUs2O0Surftimeprefactor2O75Step = std::make_shared<SurferUs2O0Surftimeprefactor2O75Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor2O75Step);
        surfer__us_2o0__surftimeprefactor_2o75Index = sObjectsStaticSteps.size() - 1;
        // // surfer__us_2o0__surftimeprefactor_3o0
        sSurferUs2O0Surftimeprefactor3O0Step = std::make_shared<SurferUs2O0Surftimeprefactor3O0Step>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sSurferUs2O0Surftimeprefactor3O0Step);
        surfer__us_2o0__surftimeprefactor_3o0Index = sObjectsStaticSteps.size() - 1;
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
