#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_1O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_1O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_20o0__surftimeconst_1o0/px/choice.h"
#include "param/post/objects/surfer__us_20o0__surftimeconst_1o0/py/choice.h"
#include "param/post/objects/surfer__us_20o0__surftimeconst_1o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs20O0Surftimeconst1O0 post processing parameters
template<typename TypeSurferUs20O0Surftimeconst1O0Step>
struct PostSurferUs20O0Surftimeconst1O0Parameters {
    std::string name = "surfer__us_20o0__surftimeconst_1o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs20O0Surftimeconst1O0Step>>> data;
    PostSurferUs20O0Surftimeconst1O0Parameters(std::shared_ptr<TypeSurferUs20O0Surftimeconst1O0Step> sSurferUs20O0Surftimeconst1O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs20O0Surftimeconst1O0Px<TypeSurferUs20O0Surftimeconst1O0Step>>(sSurferUs20O0Surftimeconst1O0Step));
        data.push_back(std::make_shared<PostSurferUs20O0Surftimeconst1O0Py<TypeSurferUs20O0Surftimeconst1O0Step>>(sSurferUs20O0Surftimeconst1O0Step));
        data.push_back(std::make_shared<PostSurferUs20O0Surftimeconst1O0Pz<TypeSurferUs20O0Surftimeconst1O0Step>>(sSurferUs20O0Surftimeconst1O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
