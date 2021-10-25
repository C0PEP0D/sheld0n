#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_5O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_9O0__SURFTIMECONST_5O0_PARAMETERS_H
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
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/px/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/py/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/pz/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j00/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j01/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j02/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j10/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j11/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j12/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j20/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j21/choice.h"
#include "param/post/objects/surfer__us_9o0__surftimeconst_5o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// SurferUs9O0Surftimeconst5O0 post processing parameters
template<typename TypeSurferUs9O0Surftimeconst5O0Step>
struct PostSurferUs9O0Surftimeconst5O0Parameters {
    std::string name = "surfer__us_9o0__surftimeconst_5o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeSurferUs9O0Surftimeconst5O0Step>>> data;
    PostSurferUs9O0Surftimeconst5O0Parameters(std::shared_ptr<TypeSurferUs9O0Surftimeconst5O0Step> sSurferUs9O0Surftimeconst5O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0Px<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0Py<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0Pz<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J00<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J01<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J02<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J10<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J11<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J12<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J20<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J21<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        data.push_back(std::make_shared<PostSurferUs9O0Surftimeconst5O0J22<TypeSurferUs9O0Surftimeconst5O0Step>>(sSurferUs9O0Surftimeconst5O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
