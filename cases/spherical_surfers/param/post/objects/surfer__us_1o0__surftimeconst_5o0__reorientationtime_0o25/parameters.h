#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_5O0__REORIENTATIONTIME_0O25_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_5O0__REORIENTATIONTIME_0O25_PARAMETERS_H
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
#include "param/post/objects/surfer__us_1o0__surftimeconst_5o0__reorientationtime_0o25/px/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_5o0__reorientationtime_0o25/py/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_5o0__reorientationtime_0o25/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs1O0Surftimeconst5O0Reorientationtime0O25 post processing parameters
template<typename TypeSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step>
struct PostSurferUs1O0Surftimeconst5O0Reorientationtime0O25Parameters {
    std::string name = "surfer__us_1o0__surftimeconst_5o0__reorientationtime_0o25";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step>>> data;
    PostSurferUs1O0Surftimeconst5O0Reorientationtime0O25Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step> sSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst5O0Reorientationtime0O25Px<TypeSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step>>(sSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst5O0Reorientationtime0O25Py<TypeSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step>>(sSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst5O0Reorientationtime0O25Pz<TypeSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step>>(sSurferUs1O0Surftimeconst5O0Reorientationtime0O25Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
