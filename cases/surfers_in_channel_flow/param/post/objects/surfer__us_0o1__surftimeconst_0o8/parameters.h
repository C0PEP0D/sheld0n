#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O8_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O8_PARAMETERS_H
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
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o8/px/choice.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o8/py/choice.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o8/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O1Surftimeconst0O8 post processing parameters
template<typename TypeSurferUs0O1Surftimeconst0O8Step>
struct PostSurferUs0O1Surftimeconst0O8Parameters {
    std::string name = "surfer__us_0o1__surftimeconst_0o8";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs0O1Surftimeconst0O8Step>>> data;
    PostSurferUs0O1Surftimeconst0O8Parameters(std::shared_ptr<TypeSurferUs0O1Surftimeconst0O8Step> sSurferUs0O1Surftimeconst0O8Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O1Surftimeconst0O8Px<TypeSurferUs0O1Surftimeconst0O8Step>>(sSurferUs0O1Surftimeconst0O8Step));
        data.push_back(std::make_shared<PostSurferUs0O1Surftimeconst0O8Py<TypeSurferUs0O1Surftimeconst0O8Step>>(sSurferUs0O1Surftimeconst0O8Step));
        data.push_back(std::make_shared<PostSurferUs0O1Surftimeconst0O8Pz<TypeSurferUs0O1Surftimeconst0O8Step>>(sSurferUs0O1Surftimeconst0O8Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
