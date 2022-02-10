#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O8_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O8_PARAMETERS_H
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
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o8/px/choice.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o8/py/choice.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o8/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs2O0Surftimeconst0O8 post processing parameters
template<typename TypeSurferUs2O0Surftimeconst0O8Step>
struct PostSurferUs2O0Surftimeconst0O8Parameters {
    std::string name = "surfer__us_2o0__surftimeconst_0o8";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs2O0Surftimeconst0O8Step>>> data;
    PostSurferUs2O0Surftimeconst0O8Parameters(std::shared_ptr<TypeSurferUs2O0Surftimeconst0O8Step> sSurferUs2O0Surftimeconst0O8Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs2O0Surftimeconst0O8Px<TypeSurferUs2O0Surftimeconst0O8Step>>(sSurferUs2O0Surftimeconst0O8Step));
        data.push_back(std::make_shared<PostSurferUs2O0Surftimeconst0O8Py<TypeSurferUs2O0Surftimeconst0O8Step>>(sSurferUs2O0Surftimeconst0O8Step));
        data.push_back(std::make_shared<PostSurferUs2O0Surftimeconst0O8Pz<TypeSurferUs2O0Surftimeconst0O8Step>>(sSurferUs2O0Surftimeconst0O8Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
