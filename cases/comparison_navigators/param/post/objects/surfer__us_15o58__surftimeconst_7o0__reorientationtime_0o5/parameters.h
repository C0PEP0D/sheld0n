#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_15O58__SURFTIMECONST_7O0__REORIENTATIONTIME_0O5_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_15O58__SURFTIMECONST_7O0__REORIENTATIONTIME_0O5_PARAMETERS_H
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
#include "param/post/objects/surfer__us_15o58__surftimeconst_7o0__reorientationtime_0o5/px/choice.h"
#include "param/post/objects/surfer__us_15o58__surftimeconst_7o0__reorientationtime_0o5/py/choice.h"
#include "param/post/objects/surfer__us_15o58__surftimeconst_7o0__reorientationtime_0o5/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs15O58Surftimeconst7O0Reorientationtime0O5 post processing parameters
template<typename TypeSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step>
struct PostSurferUs15O58Surftimeconst7O0Reorientationtime0O5Parameters {
    std::string name = "surfer__us_15o58__surftimeconst_7o0__reorientationtime_0o5";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step>>> data;
    PostSurferUs15O58Surftimeconst7O0Reorientationtime0O5Parameters(std::shared_ptr<TypeSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step> sSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs15O58Surftimeconst7O0Reorientationtime0O5Px<TypeSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step>>(sSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<PostSurferUs15O58Surftimeconst7O0Reorientationtime0O5Py<TypeSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step>>(sSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step));
        data.push_back(std::make_shared<PostSurferUs15O58Surftimeconst7O0Reorientationtime0O5Pz<TypeSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step>>(sSurferUs15O58Surftimeconst7O0Reorientationtime0O5Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
