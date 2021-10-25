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
#include "param/env/objects/tracers/choice.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct ObjectsParameters {
    // FLAG: DECLARE OBJECT BEGIN
    std::shared_ptr<TracersStep> sTracersStep;
    unsigned int tracersIndex;
    // FLAG: DECLARE OBJECT END
    
    // construct data
    std::vector<std::shared_ptr<StepObject>> data;
    ObjectsParameters(std::shared_ptr<Flow> sFlow, Objects<ObjectsParameters>* pObjects) {
        // FLAG: MAKE OBJECT BEGIN
        // // tracers
        sTracersStep = std::make_shared<TracersStep>(sFlow, pObjects);
        data.push_back(sTracersStep);
        tracersIndex = data.size() - 1;
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
