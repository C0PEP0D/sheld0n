#ifndef C0P_PARAM_INIT_OBJECTS_PARAPETERS_H
#define C0P_PARAM_INIT_OBJECTS_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <vector>
// app include
#include "core/init/objects/object/core.h"
#include "core/init/objects/prop.h"
// FLAG: INCLUDE OBJECT BEGIN
#include "param/init/objects/object/parameters.h"
#include "param/init/objects/dobject/parameters.h"
// FLAG: INCLUDE OBJECT END

namespace c0p {

struct InitObjectsParameters {
    // make data
    std::vector<std::shared_ptr<InitInitStaticBase>> sInitsStatic;
    std::vector<std::shared_ptr<InitInitDynamicBase>> sInitsDynamic;
    InitObjectsParameters(std::shared_ptr<TypeObjectsParameters> sObjectsParameters) {
        // FLAG: MAKE OBJECT BEGIN
        sInitsStatic.push_back(std::make_shared<InitInitStatic<InitObjectParameters, ObjectStep>>(sObjectsParameters->sObjectStep));
        sInitsDynamic.push_back(std::make_shared<InitInitDynamic<InitDobjectParameters, DobjectStep>>(sObjectsParameters->sDobjectStep));
        // FLAG: MAKE OBJECT END
    }
};

}

#endif
