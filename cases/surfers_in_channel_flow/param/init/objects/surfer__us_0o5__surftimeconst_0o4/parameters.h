#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O4_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O4_PARAMETERS_H
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
#include "param/init/objects/surfer__us_0o5__surftimeconst_0o4/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs0O5Surftimeconst0O4Step>
struct InitSurferUs0O5Surftimeconst0O4Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeSurferUs0O5Surftimeconst0O4Step>>> sInits;
    InitSurferUs0O5Surftimeconst0O4Parameters(std::shared_ptr<TypeSurferUs0O5Surftimeconst0O4Step> sSurferUs0O5Surftimeconst0O4Step) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs0O5Surftimeconst0O4Pos<TypeSurferUs0O5Surftimeconst0O4Step>>(sSurferUs0O5Surftimeconst0O4Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
