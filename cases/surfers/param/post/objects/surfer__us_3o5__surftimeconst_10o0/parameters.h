#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_3O5__SURFTIMECONST_10O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_3O5__SURFTIMECONST_10O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_3o5__surftimeconst_10o0/px/choice.h"
#include "param/post/objects/surfer__us_3o5__surftimeconst_10o0/py/choice.h"
#include "param/post/objects/surfer__us_3o5__surftimeconst_10o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs3O5Surftimeconst10O0 post processing parameters
template<typename TypeSurferUs3O5Surftimeconst10O0Step>
struct PostSurferUs3O5Surftimeconst10O0Parameters {
    std::string name = "surfer__us_3o5__surftimeconst_10o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs3O5Surftimeconst10O0Step>>> data;
    PostSurferUs3O5Surftimeconst10O0Parameters(std::shared_ptr<TypeSurferUs3O5Surftimeconst10O0Step> sSurferUs3O5Surftimeconst10O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs3O5Surftimeconst10O0Px<TypeSurferUs3O5Surftimeconst10O0Step>>(sSurferUs3O5Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs3O5Surftimeconst10O0Py<TypeSurferUs3O5Surftimeconst10O0Step>>(sSurferUs3O5Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs3O5Surftimeconst10O0Pz<TypeSurferUs3O5Surftimeconst10O0Step>>(sSurferUs3O5Surftimeconst10O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
