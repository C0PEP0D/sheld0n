#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_5O0__SURFTIMECONST_6O0_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_5O0__SURFTIMECONST_6O0_PARAMETERS_H
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
#include "param/init/objects/surfer__us_5o0__surftimeconst_6o0/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs5O0Surftimeconst6O0Step>
struct InitSurferUs5O0Surftimeconst6O0Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeSurferUs5O0Surftimeconst6O0Step>>> data;
    InitSurferUs5O0Surftimeconst6O0Parameters(std::shared_ptr<TypeSurferUs5O0Surftimeconst6O0Step> sSurferUs5O0Surftimeconst6O0Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitSurferUs5O0Surftimeconst6O0Pos<TypeSurferUs5O0Surftimeconst6O0Step>>(sSurferUs5O0Surftimeconst6O0Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
