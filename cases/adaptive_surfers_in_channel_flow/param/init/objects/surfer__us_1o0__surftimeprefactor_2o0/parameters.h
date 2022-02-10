#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_2O0_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_2O0_PARAMETERS_H
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
#include "param/init/objects/surfer__us_1o0__surftimeprefactor_2o0/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs1O0Surftimeprefactor2O0Step>
struct InitSurferUs1O0Surftimeprefactor2O0Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeSurferUs1O0Surftimeprefactor2O0Step>>> sInits;
    InitSurferUs1O0Surftimeprefactor2O0Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeprefactor2O0Step> sSurferUs1O0Surftimeprefactor2O0Step) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs1O0Surftimeprefactor2O0Pos<TypeSurferUs1O0Surftimeprefactor2O0Step>>(sSurferUs1O0Surftimeprefactor2O0Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
