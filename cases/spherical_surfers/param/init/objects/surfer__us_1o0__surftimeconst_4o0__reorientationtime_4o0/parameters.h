#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_4O0__REORIENTATIONTIME_4O0_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMECONST_4O0__REORIENTATIONTIME_4O0_PARAMETERS_H
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
#include "param/init/objects/surfer__us_1o0__surftimeconst_4o0__reorientationtime_4o0/pos/choice.h"
#include "param/init/objects/surfer__us_1o0__surftimeconst_4o0__reorientationtime_4o0/orient/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step>
struct InitSurferUs1O0Surftimeconst4O0Reorientationtime4O0Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step>>> data;
    InitSurferUs1O0Surftimeconst4O0Reorientationtime4O0Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step> sSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitSurferUs1O0Surftimeconst4O0Reorientationtime4O0Pos<TypeSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step>>(sSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step));
        data.push_back(std::make_shared<InitSurferUs1O0Surftimeconst4O0Reorientationtime4O0Orient<TypeSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step>>(sSurferUs1O0Surftimeconst4O0Reorientationtime4O0Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
