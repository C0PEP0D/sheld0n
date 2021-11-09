#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_6O0__SURFTIMECONST_0O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_6O0__SURFTIMECONST_0O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_6o0__surftimeconst_0o0/px/choice.h"
#include "param/post/objects/surfer__us_6o0__surftimeconst_0o0/py/choice.h"
#include "param/post/objects/surfer__us_6o0__surftimeconst_0o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs6O0Surftimeconst0O0 post processing parameters
template<typename TypeSurferUs6O0Surftimeconst0O0Step>
struct PostSurferUs6O0Surftimeconst0O0Parameters {
    std::string name = "surfer__us_6o0__surftimeconst_0o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs6O0Surftimeconst0O0Step>>> data;
    PostSurferUs6O0Surftimeconst0O0Parameters(std::shared_ptr<TypeSurferUs6O0Surftimeconst0O0Step> sSurferUs6O0Surftimeconst0O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs6O0Surftimeconst0O0Px<TypeSurferUs6O0Surftimeconst0O0Step>>(sSurferUs6O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs6O0Surftimeconst0O0Py<TypeSurferUs6O0Surftimeconst0O0Step>>(sSurferUs6O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs6O0Surftimeconst0O0Pz<TypeSurferUs6O0Surftimeconst0O0Step>>(sSurferUs6O0Surftimeconst0O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
