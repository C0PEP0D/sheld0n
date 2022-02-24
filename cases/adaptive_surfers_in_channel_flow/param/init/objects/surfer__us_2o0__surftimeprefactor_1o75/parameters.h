#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O75_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O75_PARAMETERS_H
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
#include "param/init/objects/surfer__us_2o0__surftimeprefactor_1o75/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeSurferUs2O0Surftimeprefactor1O75Step>
struct InitSurferUs2O0Surftimeprefactor1O75Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeSurferUs2O0Surftimeprefactor1O75Step>>> sInits;
    InitSurferUs2O0Surftimeprefactor1O75Parameters(std::shared_ptr<TypeSurferUs2O0Surftimeprefactor1O75Step> sSurferUs2O0Surftimeprefactor1O75Step) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitSurferUs2O0Surftimeprefactor1O75Pos<TypeSurferUs2O0Surftimeprefactor1O75Step>>(sSurferUs2O0Surftimeprefactor1O75Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
