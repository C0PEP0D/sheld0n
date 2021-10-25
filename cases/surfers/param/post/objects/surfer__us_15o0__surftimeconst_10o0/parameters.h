#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_15O0__SURFTIMECONST_10O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_15O0__SURFTIMECONST_10O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/px/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/py/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/pz/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j00/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j01/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j02/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j10/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j11/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j12/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j20/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j21/choice.h"
#include "param/post/objects/surfer__us_15o0__surftimeconst_10o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs15O0Surftimeconst10O0 post processing parameters
template<typename TypeSurferUs15O0Surftimeconst10O0Step>
struct PostSurferUs15O0Surftimeconst10O0Parameters {
    std::string name = "surfer__us_15o0__surftimeconst_10o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs15O0Surftimeconst10O0Step>>> data;
    PostSurferUs15O0Surftimeconst10O0Parameters(std::shared_ptr<TypeSurferUs15O0Surftimeconst10O0Step> sSurferUs15O0Surftimeconst10O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0Px<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0Py<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0Pz<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J00<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J01<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J02<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J10<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J11<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J12<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J20<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J21<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        data.push_back(std::make_shared<PostSurferUs15O0Surftimeconst10O0J22<TypeSurferUs15O0Surftimeconst10O0Step>>(sSurferUs15O0Surftimeconst10O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
