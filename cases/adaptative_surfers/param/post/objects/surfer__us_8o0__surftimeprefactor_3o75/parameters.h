#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_3O75_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_3O75_PARAMETERS_H
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
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o75/px/choice.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o75/py/choice.h"
#include "param/post/objects/surfer__us_8o0__surftimeprefactor_3o75/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs8O0Surftimeprefactor3O75 post processing parameters
template<typename TypeSurferUs8O0Surftimeprefactor3O75Step>
struct PostSurferUs8O0Surftimeprefactor3O75Parameters {
    std::string name = "surfer__us_8o0__surftimeprefactor_3o75";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs8O0Surftimeprefactor3O75Step>>> data;
    PostSurferUs8O0Surftimeprefactor3O75Parameters(std::shared_ptr<TypeSurferUs8O0Surftimeprefactor3O75Step> sSurferUs8O0Surftimeprefactor3O75Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeprefactor3O75Px<TypeSurferUs8O0Surftimeprefactor3O75Step>>(sSurferUs8O0Surftimeprefactor3O75Step));
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeprefactor3O75Py<TypeSurferUs8O0Surftimeprefactor3O75Step>>(sSurferUs8O0Surftimeprefactor3O75Step));
        data.push_back(std::make_shared<PostSurferUs8O0Surftimeprefactor3O75Pz<TypeSurferUs8O0Surftimeprefactor3O75Step>>(sSurferUs8O0Surftimeprefactor3O75Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
