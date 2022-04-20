#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O4__SURFTIMECONST_1O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O4__SURFTIMECONST_1O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_0o4__surftimeconst_1o0/pos/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O4Surftimeconst1O0 post processing parameters
template<typename TypeObjectStep>
struct PostSurferUs0O4Surftimeconst1O0Parameters {
    std::string name = "surfer__us_0o4__surftimeconst_1o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostSurferUs0O4Surftimeconst1O0Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O4Surftimeconst1O0Pos<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
