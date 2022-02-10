#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o0/px/choice.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o0/py/choice.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O1Surftimeconst0O0 post processing parameters
template<typename TypeSurferUs0O1Surftimeconst0O0Step>
struct PostSurferUs0O1Surftimeconst0O0Parameters {
    std::string name = "surfer__us_0o1__surftimeconst_0o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs0O1Surftimeconst0O0Step>>> data;
    PostSurferUs0O1Surftimeconst0O0Parameters(std::shared_ptr<TypeSurferUs0O1Surftimeconst0O0Step> sSurferUs0O1Surftimeconst0O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O1Surftimeconst0O0Px<TypeSurferUs0O1Surftimeconst0O0Step>>(sSurferUs0O1Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs0O1Surftimeconst0O0Py<TypeSurferUs0O1Surftimeconst0O0Step>>(sSurferUs0O1Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs0O1Surftimeconst0O0Pz<TypeSurferUs0O1Surftimeconst0O0Step>>(sSurferUs0O1Surftimeconst0O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
