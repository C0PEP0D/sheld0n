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
#include "param/env/objects/pagent/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
    // FLAG: DECLARE OBJECT BEGIN
    std::shared_ptr<PagentStep> sPagentStep;
    unsigned int pagentIndex;
    // FLAG: DECLARE OBJECT END
    
    // construct data
    std::vector<std::shared_ptr<StepObjectStatic>> sObjectsStaticSteps;
    std::vector<std::shared_ptr<StepObjectDynamic>> sObjectsDynamicSteps;
    ObjectsParameters(std::shared_ptr<Flow> sFlow, std::shared_ptr<Objects> sObjects) {
        // FLAG: MAKE OBJECT BEGIN
        // // pagent
        sPagentStep = std::make_shared<PagentStep>(sFlow, sObjects);
        sObjectsStaticSteps.push_back(sPagentStep);
        pagentIndex = sObjectsStaticSteps.size() - 1;
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
