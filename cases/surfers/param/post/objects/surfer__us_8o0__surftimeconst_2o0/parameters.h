#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMECONST_2O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMECONST_2O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_8o0__surftimeconst_2o0/px/choice.h"
#include "param/post/objects/surfer__us_8o0__surftimeconst_2o0/py/choice.h"
#include "param/post/objects/surfer__us_8o0__surftimeconst_2o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs8O0Surftimeconst2O0 post processing parameters
template<typename TypeSurferUs8O0Surftimeconst2O0Step>
struct PostSurferUs8O0Surftimeconst2O0Parameters {
    std::string name = "surfer__us_8o0__surftimeconst_2o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs8O0Surftimeconst2O0Step>>> data;
    PostSurferUs8O0Surftimeconst2O0Parameters(std::shared_ptr<TypeSurferUs8O0Surftimeconst2O0Step> sSurferUs8O0Surftimeconst2O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeconst2O0Px<TypeSurferUs8O0Surftimeconst2O0Step>>(sSurferUs8O0Surftimeconst2O0Step));
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeconst2O0Py<TypeSurferUs8O0Surftimeconst2O0Step>>(sSurferUs8O0Surftimeconst2O0Step));
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeconst2O0Pz<TypeSurferUs8O0Surftimeconst2O0Step>>(sSurferUs8O0Surftimeconst2O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
