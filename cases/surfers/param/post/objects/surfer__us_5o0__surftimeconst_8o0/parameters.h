#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_8O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_8O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_5o0__surftimeconst_8o0/px/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_8o0/py/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_8o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs5O0Surftimeconst8O0 post processing parameters
template<typename TypeSurferUs5O0Surftimeconst8O0Step>
struct PostSurferUs5O0Surftimeconst8O0Parameters {
    std::string name = "surfer__us_5o0__surftimeconst_8o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs5O0Surftimeconst8O0Step>>> data;
    PostSurferUs5O0Surftimeconst8O0Parameters(std::shared_ptr<TypeSurferUs5O0Surftimeconst8O0Step> sSurferUs5O0Surftimeconst8O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst8O0Px<TypeSurferUs5O0Surftimeconst8O0Step>>(sSurferUs5O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst8O0Py<TypeSurferUs5O0Surftimeconst8O0Step>>(sSurferUs5O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst8O0Pz<TypeSurferUs5O0Surftimeconst8O0Step>>(sSurferUs5O0Surftimeconst8O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
