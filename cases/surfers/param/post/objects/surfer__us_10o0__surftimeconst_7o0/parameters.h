#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_10O0__SURFTIMECONST_7O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_10O0__SURFTIMECONST_7O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/px/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/py/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/pz/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j00/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j01/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j02/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j10/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j11/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j12/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j20/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j21/choice.h"
#include "param/post/objects/surfer__us_10o0__surftimeconst_7o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs10O0Surftimeconst7O0 post processing parameters
template<typename TypeSurferUs10O0Surftimeconst7O0Step>
struct PostSurferUs10O0Surftimeconst7O0Parameters {
    std::string name = "surfer__us_10o0__surftimeconst_7o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs10O0Surftimeconst7O0Step>>> data;
    PostSurferUs10O0Surftimeconst7O0Parameters(std::shared_ptr<TypeSurferUs10O0Surftimeconst7O0Step> sSurferUs10O0Surftimeconst7O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0Px<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0Py<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0Pz<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J00<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J01<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J02<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J10<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J11<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J12<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J20<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J21<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        data.push_back(std::make_shared<PostSurferUs10O0Surftimeconst7O0J22<TypeSurferUs10O0Surftimeconst7O0Step>>(sSurferUs10O0Surftimeconst7O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
