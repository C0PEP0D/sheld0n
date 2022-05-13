#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_5O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_5O0_PARAMETERS_H
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
#include "param/post/objects/surfer__vs_4o0__surftimeconst_5o0/pos/choice.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_5o0/grad/choice.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_5o0/vel/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferVs4O0Surftimeconst5O0 post processing parameters
template<typename TypeObjectStep>
struct PostSurferVs4O0Surftimeconst5O0Parameters {
    std::string name = "surfer__vs_4o0__surftimeconst_5o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostSurferVs4O0Surftimeconst5O0Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferVs4O0Surftimeconst5O0Pos<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs4O0Surftimeconst5O0Grad<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs4O0Surftimeconst5O0Vel<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
