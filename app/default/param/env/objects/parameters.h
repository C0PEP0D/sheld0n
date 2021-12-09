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
#include "param/env/objects/object/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
    // FLAG: DECLARE OBJECT BEGIN
    std::shared_ptr<ObjectStep> sObjectStep;
    unsigned int objectIndex;
    // FLAG: DECLARE OBJECT END
    
    // construct data
    std::vector<std::shared_ptr<StepObjectStatic>> sObjectsStaticSteps;
    std::vector<std::shared_ptr<StepObjectDynamic>> sObjectsDynamicSteps;
    ObjectsParameters(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) {
        // FLAG: MAKE OBJECT BEGIN
        // // object
        sObjectStep = std::make_shared<ObjectStep>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sObjectStep);
        objectIndex = sObjectsStaticSteps.size() - 1;
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
