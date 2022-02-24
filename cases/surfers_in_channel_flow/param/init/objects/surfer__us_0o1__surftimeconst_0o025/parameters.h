#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O025_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O025_PARAMETERS_H
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
#include "param/init/objects/surfer__us_0o1__surftimeconst_0o025/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs0O1Surftimeconst0O025Step>
struct InitSurferUs0O1Surftimeconst0O025Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeSurferUs0O1Surftimeconst0O025Step>>> sInits;
    InitSurferUs0O1Surftimeconst0O025Parameters(std::shared_ptr<TypeSurferUs0O1Surftimeconst0O025Step> sSurferUs0O1Surftimeconst0O025Step) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs0O1Surftimeconst0O025Pos<TypeSurferUs0O1Surftimeconst0O025Step>>(sSurferUs0O1Surftimeconst0O025Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
