#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_2O75_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_2O75_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMANDS ARE USED

// std include
#include <memory> // shared_ptr
#include <vector>
#include <string>
// app include
#include "core/post/objects/object/post/core.h"
// FLAG: INCLUDE POST BEGIN
#include "param/post/objects/surfer__us_0o2__surftimeprefactor_2o75/pos/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O2Surftimeprefactor2O75 post processing parameters
template<typename TypeObjectStep>
struct PostSurferUs0O2Surftimeprefactor2O75Parameters {
    std::string name = "surfer__us_0o2__surftimeprefactor_2o75";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostSurferUs0O2Surftimeprefactor2O75Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O2Surftimeprefactor2O75Pos<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
