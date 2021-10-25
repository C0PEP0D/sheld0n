#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_0O5_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_0O5_PARAMETERS_H
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
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o5/px/choice.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o5/py/choice.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_0o5/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs8O0Surftimeprefactor0O5 post processing parameters
template<typename TypeSurferUs8O0Surftimeprefactor0O5Step>
struct PostSurferUs8O0Surftimeprefactor0O5Parameters {
    std::string name = "surfer__us_8o0__surftimeprefactor_0o5";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs8O0Surftimeprefactor0O5Step>>> data;
    PostSurferUs8O0Surftimeprefactor0O5Parameters(std::shared_ptr<TypeSurferUs8O0Surftimeprefactor0O5Step> sSurferUs8O0Surftimeprefactor0O5Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeprefactor0O5Px<TypeSurferUs8O0Surftimeprefactor0O5Step>>(sSurferUs8O0Surftimeprefactor0O5Step));
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeprefactor0O5Py<TypeSurferUs8O0Surftimeprefactor0O5Step>>(sSurferUs8O0Surftimeprefactor0O5Step));
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeprefactor0O5Pz<TypeSurferUs8O0Surftimeprefactor0O5Step>>(sSurferUs8O0Surftimeprefactor0O5Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
