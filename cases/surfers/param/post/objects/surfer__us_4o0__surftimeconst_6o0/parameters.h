#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_6O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMECONST_6O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/px/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/py/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/pz/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j00/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j01/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j02/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j10/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j11/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j12/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j20/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j21/choice.h"
#include "param/post/objects/surfer__us_4o0__surftimeconst_6o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs4O0Surftimeconst6O0 post processing parameters
template<typename TypeSurferUs4O0Surftimeconst6O0Step>
struct PostSurferUs4O0Surftimeconst6O0Parameters {
    std::string name = "surfer__us_4o0__surftimeconst_6o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs4O0Surftimeconst6O0Step>>> data;
    PostSurferUs4O0Surftimeconst6O0Parameters(std::shared_ptr<TypeSurferUs4O0Surftimeconst6O0Step> sSurferUs4O0Surftimeconst6O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0Px<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0Py<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0Pz<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J00<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J01<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J02<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J10<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J11<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J12<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J20<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J21<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        data.push_back(std::make_shared<PostSurferUs4O0Surftimeconst6O0J22<TypeSurferUs4O0Surftimeconst6O0Step>>(sSurferUs4O0Surftimeconst6O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
