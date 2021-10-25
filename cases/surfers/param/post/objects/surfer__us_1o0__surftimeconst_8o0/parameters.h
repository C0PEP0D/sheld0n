#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/px/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/py/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/pz/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j00/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j01/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j02/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j10/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j11/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j12/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j20/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j21/choice.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_8o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs1O0Surftimeconst8O0 post processing parameters
template<typename TypeSurferUs1O0Surftimeconst8O0Step>
struct PostSurferUs1O0Surftimeconst8O0Parameters {
    std::string name = "surfer__us_1o0__surftimeconst_8o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs1O0Surftimeconst8O0Step>>> data;
    PostSurferUs1O0Surftimeconst8O0Parameters(std::shared_ptr<TypeSurferUs1O0Surftimeconst8O0Step> sSurferUs1O0Surftimeconst8O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0Px<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0Py<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0Pz<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J00<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J01<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J02<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J10<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J11<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J12<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J20<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J21<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        data.push_back(std::make_shared<PostSurferUs1O0Surftimeconst8O0J22<TypeSurferUs1O0Surftimeconst8O0Step>>(sSurferUs1O0Surftimeconst8O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
