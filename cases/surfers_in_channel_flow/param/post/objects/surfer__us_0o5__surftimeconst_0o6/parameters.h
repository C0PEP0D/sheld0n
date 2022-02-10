#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O6_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O6_PARAMETERS_H
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
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o6/px/choice.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o6/py/choice.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o6/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O5Surftimeconst0O6 post processing parameters
template<typename TypeSurferUs0O5Surftimeconst0O6Step>
struct PostSurferUs0O5Surftimeconst0O6Parameters {
    std::string name = "surfer__us_0o5__surftimeconst_0o6";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs0O5Surftimeconst0O6Step>>> data;
    PostSurferUs0O5Surftimeconst0O6Parameters(std::shared_ptr<TypeSurferUs0O5Surftimeconst0O6Step> sSurferUs0O5Surftimeconst0O6Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O6Px<TypeSurferUs0O5Surftimeconst0O6Step>>(sSurferUs0O5Surftimeconst0O6Step));
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O6Py<TypeSurferUs0O5Surftimeconst0O6Step>>(sSurferUs0O5Surftimeconst0O6Step));
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O6Pz<TypeSurferUs0O5Surftimeconst0O6Step>>(sSurferUs0O5Surftimeconst0O6Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
