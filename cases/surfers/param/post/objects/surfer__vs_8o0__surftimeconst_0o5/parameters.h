#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_0O5_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_0O5_PARAMETERS_H
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
#include "param/post/objects/surfer__vs_8o0__surftimeconst_0o5/pos/choice.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_0o5/grad/choice.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_0o5/vel/choice.h"
#include "param/post/objects/surfer__vs_8o0__surftimeconst_0o5/dir/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferVs8O0Surftimeconst0O5 post processing parameters
template<typename TypeObjectStep>
struct PostSurferVs8O0Surftimeconst0O5Parameters {
    std::string name = "surfer__vs_8o0__surftimeconst_0o5";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostSurferVs8O0Surftimeconst0O5Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferVs8O0Surftimeconst0O5Pos<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs8O0Surftimeconst0O5Grad<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs8O0Surftimeconst0O5Vel<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostSurferVs8O0Surftimeconst0O5Dir<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
