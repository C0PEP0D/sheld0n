#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_15O58__SURFTIMECONST_2O0__REORIENTATIONTIME_0O5_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_15O58__SURFTIMECONST_2O0__REORIENTATIONTIME_0O5_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <memory> // shared_ptr
#include <vector>
#include <string>
// app include
#include "core/init/objects/object/init/core.h"
// FLAG: INCLUDE INIT BEGIN
#include "param/init/objects/surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5/pos/choice.h"
#include "param/init/objects/surfer__us_15o58__surftimeconst_2o0__reorientationtime_0o5/orient/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeObjectStep>
struct InitSurferUs15O58Surftimeconst2O0Reorientationtime0O5Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeObjectStep>>> sInits;
    InitSurferUs15O58Surftimeconst2O0Reorientationtime0O5Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs15O58Surftimeconst2O0Reorientationtime0O5Pos<TypeObjectStep>>(sObjectStep));
        sInits.push_back(std::make_shared<InitSurferUs15O58Surftimeconst2O0Reorientationtime0O5Orient<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
