#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O3_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O3_PARAMETERS_H
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
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o3/px/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o3/py/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o3/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs1O0Surftimeconst0O3 post processing parameters
template<typename TypeSurferUs1O0Surftimeconst0O3Step>
struct PostSurferUs1O0Surftimeconst0O3Parameters {
    std::string name = "surfer__us_1o0__surftimeconst_0o3";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs1O0Surftimeconst0O3Step>>> data;
    PostSurferUs1O0Surftimeconst0O3Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst0O3Step> sSurferUs1O0Surftimeconst0O3Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O3Px<TypeSurferUs1O0Surftimeconst0O3Step>>(sSurferUs1O0Surftimeconst0O3Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O3Py<TypeSurferUs1O0Surftimeconst0O3Step>>(sSurferUs1O0Surftimeconst0O3Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O3Pz<TypeSurferUs1O0Surftimeconst0O3Step>>(sSurferUs1O0Surftimeconst0O3Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
