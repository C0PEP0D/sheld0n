#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O05_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_0O05_PARAMETERS_H
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
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o05/px/choice.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o05/py/choice.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_0o05/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs0O5Surftimeconst0O05 post processing parameters
template<typename TypeSurferUs0O5Surftimeconst0O05Step>
struct PostSurferUs0O5Surftimeconst0O05Parameters {
    std::string name = "surfer__us_0o5__surftimeconst_0o05";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs0O5Surftimeconst0O05Step>>> data;
    PostSurferUs0O5Surftimeconst0O05Parameters(std::shared_ptr<TypeSurferUs0O5Surftimeconst0O05Step> sSurferUs0O5Surftimeconst0O05Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O05Px<TypeSurferUs0O5Surftimeconst0O05Step>>(sSurferUs0O5Surftimeconst0O05Step));
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O05Py<TypeSurferUs0O5Surftimeconst0O05Step>>(sSurferUs0O5Surftimeconst0O05Step));
        data.push_back(std::make_shared<PostSurferUs0O5Surftimeconst0O05Pz<TypeSurferUs0O5Surftimeconst0O05Step>>(sSurferUs0O5Surftimeconst0O05Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
