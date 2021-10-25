#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_0O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_5O0__SURFTIMECONST_0O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/px/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/py/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/pz/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j00/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j01/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j02/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j10/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j11/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j12/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j20/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j21/choice.h"
#include "param/post/objects/surfer__us_5o0__surftimeconst_0o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs5O0Surftimeconst0O0 post processing parameters
template<typename TypeSurferUs5O0Surftimeconst0O0Step>
struct PostSurferUs5O0Surftimeconst0O0Parameters {
    std::string name = "surfer__us_5o0__surftimeconst_0o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs5O0Surftimeconst0O0Step>>> data;
    PostSurferUs5O0Surftimeconst0O0Parameters(std::shared_ptr<TypeSurferUs5O0Surftimeconst0O0Step> sSurferUs5O0Surftimeconst0O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0Px<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0Py<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0Pz<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J00<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J01<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J02<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J10<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J11<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J12<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J20<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J21<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        data.push_back(std::make_shared<PostSurferUs5O0Surftimeconst0O0J22<TypeSurferUs5O0Surftimeconst0O0Step>>(sSurferUs5O0Surftimeconst0O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
