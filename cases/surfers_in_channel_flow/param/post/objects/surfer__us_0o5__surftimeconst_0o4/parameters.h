#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O4_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O4_PARAMETERS_H
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
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o4/px/choice.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o4/py/choice.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o4/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O5Surftimeconst0O4 post processing parameters
template<typename TypeSurferUs0O5Surftimeconst0O4Step>
struct PostSurferUs0O5Surftimeconst0O4Parameters {
    std::string name = "surfer__us_0o5__surftimeconst_0o4";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs0O5Surftimeconst0O4Step>>> data;
    PostSurferUs0O5Surftimeconst0O4Parameters(std::shared_ptr<TypeSurferUs0O5Surftimeconst0O4Step> sSurferUs0O5Surftimeconst0O4Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O4Px<TypeSurferUs0O5Surftimeconst0O4Step>>(sSurferUs0O5Surftimeconst0O4Step));
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O4Py<TypeSurferUs0O5Surftimeconst0O4Step>>(sSurferUs0O5Surftimeconst0O4Step));
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O4Pz<TypeSurferUs0O5Surftimeconst0O4Step>>(sSurferUs0O5Surftimeconst0O4Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
