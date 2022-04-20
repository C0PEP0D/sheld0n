#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMECONST_1O5_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMECONST_1O5_PARAMETERS_H
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
#include "param/init/objects/surfer__us_0o1__surftimeconst_1o5/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeObjectStep>
struct InitSurferUs0O1Surftimeconst1O5Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeObjectStep>>> sInits;
    InitSurferUs0O1Surftimeconst1O5Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs0O1Surftimeconst1O5Pos<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
