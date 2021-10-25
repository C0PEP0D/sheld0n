#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_3O0__SURFTIMECONST_10O0_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_3O0__SURFTIMECONST_10O0_PARAMETERS_H
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
#include "param/init/objects/surfer__us_3o0__surftimeconst_10o0/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs3O0Surftimeconst10O0Step>
struct InitSurferUs3O0Surftimeconst10O0Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeSurferUs3O0Surftimeconst10O0Step>>> data;
    InitSurferUs3O0Surftimeconst10O0Parameters(std::shared_ptr<TypeSurferUs3O0Surftimeconst10O0Step> sSurferUs3O0Surftimeconst10O0Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitSurferUs3O0Surftimeconst10O0Pos<TypeSurferUs3O0Surftimeconst10O0Step>>(sSurferUs3O0Surftimeconst10O0Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
