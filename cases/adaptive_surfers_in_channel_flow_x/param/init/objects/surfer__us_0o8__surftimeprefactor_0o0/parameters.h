#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_0O0_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O8__SURFTIMEPREFACTOR_0O0_PARAMETERS_H
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
#include "param/init/objects/surfer__us_0o8__surftimeprefactor_0o0/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeObjectStep>
struct InitSurferUs0O8Surftimeprefactor0O0Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeObjectStep>>> sInits;
    InitSurferUs0O8Surftimeprefactor0O0Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs0O8Surftimeprefactor0O0Pos<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
