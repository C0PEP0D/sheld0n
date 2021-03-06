#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_3O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_3O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o0/px/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o0/py/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o0/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs4O0Surftimeprefactor3O0 post processing parameters
template<typename TypeSurferUs4O0Surftimeprefactor3O0Step>
struct PostSurferUs4O0Surftimeprefactor3O0Parameters {
    std::string name = "surfer__us_4o0__surftimeprefactor_3o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs4O0Surftimeprefactor3O0Step>>> data;
    PostSurferUs4O0Surftimeprefactor3O0Parameters(std::shared_ptr<TypeSurferUs4O0Surftimeprefactor3O0Step> sSurferUs4O0Surftimeprefactor3O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor3O0Px<TypeSurferUs4O0Surftimeprefactor3O0Step>>(sSurferUs4O0Surftimeprefactor3O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor3O0Py<TypeSurferUs4O0Surftimeprefactor3O0Step>>(sSurferUs4O0Surftimeprefactor3O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeprefactor3O0Pz<TypeSurferUs4O0Surftimeprefactor3O0Step>>(sSurferUs4O0Surftimeprefactor3O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
