#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O75_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O75_PARAMETERS_H
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
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o75/px/choice.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o75/py/choice.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o75/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs2O0Surftimeprefactor1O75 post processing parameters
template<typename TypeSurferUs2O0Surftimeprefactor1O75Step>
struct PostSurferUs2O0Surftimeprefactor1O75Parameters {
    std::string name = "surfer__us_2o0__surftimeprefactor_1o75";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs2O0Surftimeprefactor1O75Step>>> data;
    PostSurferUs2O0Surftimeprefactor1O75Parameters(std::shared_ptr<TypeSurferUs2O0Surftimeprefactor1O75Step> sSurferUs2O0Surftimeprefactor1O75Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs2O0Surftimeprefactor1O75Px<TypeSurferUs2O0Surftimeprefactor1O75Step>>(sSurferUs2O0Surftimeprefactor1O75Step));
        data.push_back(std::make_shared<PostSurferUs2O0Surftimeprefactor1O75Py<TypeSurferUs2O0Surftimeprefactor1O75Step>>(sSurferUs2O0Surftimeprefactor1O75Step));
        data.push_back(std::make_shared<PostSurferUs2O0Surftimeprefactor1O75Pz<TypeSurferUs2O0Surftimeprefactor1O75Step>>(sSurferUs2O0Surftimeprefactor1O75Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
