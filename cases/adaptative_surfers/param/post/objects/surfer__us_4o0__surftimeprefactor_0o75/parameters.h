#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_0O75_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_0O75_PARAMETERS_H
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
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o75/px/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o75/py/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_0o75/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs4O0Surftimeprefactor0O75 post processing parameters
template<typename TypeSurferUs4O0Surftimeprefactor0O75Step>
struct PostSurferUs4O0Surftimeprefactor0O75Parameters {
    std::string name = "surfer__us_4o0__surftimeprefactor_0o75";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs4O0Surftimeprefactor0O75Step>>> data;
    PostSurferUs4O0Surftimeprefactor0O75Parameters(std::shared_ptr<TypeSurferUs4O0Surftimeprefactor0O75Step> sSurferUs4O0Surftimeprefactor0O75Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor0O75Px<TypeSurferUs4O0Surftimeprefactor0O75Step>>(sSurferUs4O0Surftimeprefactor0O75Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor0O75Py<TypeSurferUs4O0Surftimeprefactor0O75Step>>(sSurferUs4O0Surftimeprefactor0O75Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor0O75Pz<TypeSurferUs4O0Surftimeprefactor0O75Step>>(sSurferUs4O0Surftimeprefactor0O75Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
