#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O5__SURFTIMECONST_3O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O5__SURFTIMECONST_3O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_2o5__surftimeconst_3o0/px/choice.h"
#include "param/post/objects/surfer__us_2o5__surftimeconst_3o0/py/choice.h"
#include "param/post/objects/surfer__us_2o5__surftimeconst_3o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs2O5Surftimeconst3O0 post processing parameters
template<typename TypeSurferUs2O5Surftimeconst3O0Step>
struct PostSurferUs2O5Surftimeconst3O0Parameters {
    std::string name = "surfer__us_2o5__surftimeconst_3o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs2O5Surftimeconst3O0Step>>> data;
    PostSurferUs2O5Surftimeconst3O0Parameters(std::shared_ptr<TypeSurferUs2O5Surftimeconst3O0Step> sSurferUs2O5Surftimeconst3O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs2O5Surftimeconst3O0Px<TypeSurferUs2O5Surftimeconst3O0Step>>(sSurferUs2O5Surftimeconst3O0Step));
        data.push_back(std::make_shared<PostSurferUs2O5Surftimeconst3O0Py<TypeSurferUs2O5Surftimeconst3O0Step>>(sSurferUs2O5Surftimeconst3O0Step));
        data.push_back(std::make_shared<PostSurferUs2O5Surftimeconst3O0Pz<TypeSurferUs2O5Surftimeconst3O0Step>>(sSurferUs2O5Surftimeconst3O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
