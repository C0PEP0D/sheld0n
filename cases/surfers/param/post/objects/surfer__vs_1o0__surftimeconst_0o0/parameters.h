#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_0O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_0O0_PARAMETERS_H
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
#include "param/post/objects/surfer__vs_1o0__surftimeconst_0o0/pos/choice.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_0o0/grad/choice.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_0o0/vel/choice.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_0o0/dir/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferVs1O0Surftimeconst0O0 post processing parameters
template<typename TypeObjectStep>
struct PostSurferVs1O0Surftimeconst0O0Parameters {
    std::string name = "surfer__vs_1o0__surftimeconst_0o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostSurferVs1O0Surftimeconst0O0Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferVs1O0Surftimeconst0O0Pos<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs1O0Surftimeconst0O0Grad<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs1O0Surftimeconst0O0Vel<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs1O0Surftimeconst0O0Dir<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
