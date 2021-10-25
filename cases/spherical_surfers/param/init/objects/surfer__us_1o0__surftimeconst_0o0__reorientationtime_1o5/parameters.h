#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O0__REORIENTATIONTIME_1O5_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O0__REORIENTATIONTIME_1O5_PARAMETERS_H
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
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o0__reorientationtime_1o5/pos/choice.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_0o0__reorientationtime_1o5/orient/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step>
struct InitSurferUs1O0Surftimeconst0O0Reorientationtime1O5Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step>>> data;
    InitSurferUs1O0Surftimeconst0O0Reorientationtime1O5Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step> sSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitSurferUs1O0Surftimeconst0O0Reorientationtime1O5Pos<TypeSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step>>(sSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step));
        data.push_back(std::make_shared<InitSurferUs1O0Surftimeconst0O0Reorientationtime1O5Orient<TypeSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step>>(sSurferUs1O0Surftimeconst0O0Reorientationtime1O5Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
