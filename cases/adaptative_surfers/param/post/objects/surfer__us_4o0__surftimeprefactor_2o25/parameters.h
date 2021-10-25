#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O25_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O25_PARAMETERS_H
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
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o25/px/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o25/py/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_2o25/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs4O0Surftimeprefactor2O25 post processing parameters
template<typename TypeSurferUs4O0Surftimeprefactor2O25Step>
struct PostSurferUs4O0Surftimeprefactor2O25Parameters {
    std::string name = "surfer__us_4o0__surftimeprefactor_2o25";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs4O0Surftimeprefactor2O25Step>>> data;
    PostSurferUs4O0Surftimeprefactor2O25Parameters(std::shared_ptr<TypeSurferUs4O0Surftimeprefactor2O25Step> sSurferUs4O0Surftimeprefactor2O25Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor2O25Px<TypeSurferUs4O0Surftimeprefactor2O25Step>>(sSurferUs4O0Surftimeprefactor2O25Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor2O25Py<TypeSurferUs4O0Surftimeprefactor2O25Step>>(sSurferUs4O0Surftimeprefactor2O25Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor2O25Pz<TypeSurferUs4O0Surftimeprefactor2O25Step>>(sSurferUs4O0Surftimeprefactor2O25Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
