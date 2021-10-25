#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_7O0__SURFTIMECONST_4O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_7O0__SURFTIMECONST_4O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/px/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/py/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/pz/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j00/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j01/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j02/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j10/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j11/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j12/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j20/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j21/choice.h"
#include "param/post/objects/surfer__us_7o0__surftimeconst_4o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs7O0Surftimeconst4O0 post processing parameters
template<typename TypeSurferUs7O0Surftimeconst4O0Step>
struct PostSurferUs7O0Surftimeconst4O0Parameters {
    std::string name = "surfer__us_7o0__surftimeconst_4o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs7O0Surftimeconst4O0Step>>> data;
    PostSurferUs7O0Surftimeconst4O0Parameters(std::shared_ptr<TypeSurferUs7O0Surftimeconst4O0Step> sSurferUs7O0Surftimeconst4O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0Px<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0Py<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0Pz<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J00<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J01<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J02<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J10<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J11<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J12<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J20<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J21<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        data.push_back(std::make_shared<PostSurferUs7O0Surftimeconst4O0J22<TypeSurferUs7O0Surftimeconst4O0Step>>(sSurferUs7O0Surftimeconst4O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
