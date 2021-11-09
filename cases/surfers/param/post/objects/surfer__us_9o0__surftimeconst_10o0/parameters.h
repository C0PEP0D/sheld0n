#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_10O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_10O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_9o0__surftimeconst_10o0/px/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_10o0/py/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_10o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs9O0Surftimeconst10O0 post processing parameters
template<typename TypeSurferUs9O0Surftimeconst10O0Step>
struct PostSurferUs9O0Surftimeconst10O0Parameters {
    std::string name = "surfer__us_9o0__surftimeconst_10o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs9O0Surftimeconst10O0Step>>> data;
    PostSurferUs9O0Surftimeconst10O0Parameters(std::shared_ptr<TypeSurferUs9O0Surftimeconst10O0Step> sSurferUs9O0Surftimeconst10O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst10O0Px<TypeSurferUs9O0Surftimeconst10O0Step>>(sSurferUs9O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst10O0Py<TypeSurferUs9O0Surftimeconst10O0Step>>(sSurferUs9O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst10O0Pz<TypeSurferUs9O0Surftimeconst10O0Step>>(sSurferUs9O0Surftimeconst10O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
