#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O025_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O025_PARAMETERS_H
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
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o025/px/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o025/py/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o025/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs1O0Surftimeconst0O025 post processing parameters
template<typename TypeSurferUs1O0Surftimeconst0O025Step>
struct PostSurferUs1O0Surftimeconst0O025Parameters {
    std::string name = "surfer__us_1o0__surftimeconst_0o025";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs1O0Surftimeconst0O025Step>>> data;
    PostSurferUs1O0Surftimeconst0O025Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst0O025Step> sSurferUs1O0Surftimeconst0O025Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O025Px<TypeSurferUs1O0Surftimeconst0O025Step>>(sSurferUs1O0Surftimeconst0O025Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O025Py<TypeSurferUs1O0Surftimeconst0O025Step>>(sSurferUs1O0Surftimeconst0O025Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst0O025Pz<TypeSurferUs1O0Surftimeconst0O025Step>>(sSurferUs1O0Surftimeconst0O025Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
