#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O4_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O4_PARAMETERS_H
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
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o4/px/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o4/py/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o4/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs1O0Surftimeconst0O4 post processing parameters
template<typename TypeSurferUs1O0Surftimeconst0O4Step>
struct PostSurferUs1O0Surftimeconst0O4Parameters {
    std::string name = "surfer__us_1o0__surftimeconst_0o4";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs1O0Surftimeconst0O4Step>>> data;
    PostSurferUs1O0Surftimeconst0O4Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst0O4Step> sSurferUs1O0Surftimeconst0O4Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O4Px<TypeSurferUs1O0Surftimeconst0O4Step>>(sSurferUs1O0Surftimeconst0O4Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O4Py<TypeSurferUs1O0Surftimeconst0O4Step>>(sSurferUs1O0Surftimeconst0O4Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O4Pz<TypeSurferUs1O0Surftimeconst0O4Step>>(sSurferUs1O0Surftimeconst0O4Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
