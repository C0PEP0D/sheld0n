#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O0_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O0_PARAMETERS_H
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
#include "param/post/objects/riser__us_2o0/px/choice.h"
#include "param/post/objects/riser__us_2o0/py/choice.h"
#include "param/post/objects/riser__us_2o0/pz/choice.h"
#include "param/post/objects/riser__us_2o0/j00/choice.h"
#include "param/post/objects/riser__us_2o0/j01/choice.h"
#include "param/post/objects/riser__us_2o0/j02/choice.h"
#include "param/post/objects/riser__us_2o0/j10/choice.h"
#include "param/post/objects/riser__us_2o0/j11/choice.h"
#include "param/post/objects/riser__us_2o0/j12/choice.h"
#include "param/post/objects/riser__us_2o0/j20/choice.h"
#include "param/post/objects/riser__us_2o0/j21/choice.h"
#include "param/post/objects/riser__us_2o0/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// RiserUs2O0 post processing parameters
template<typename TypeRiserUs2O0Step>
struct PostRiserUs2O0Parameters {
    std::string name = "riser__us_2o0";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeRiserUs2O0Step>>> data;
    PostRiserUs2O0Parameters(std::shared_ptr<TypeRiserUs2O0Step> sRiserUs2O0Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostRiserUs2O0Px<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0Py<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0Pz<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J00<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J01<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J02<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J10<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J11<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J12<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J20<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J21<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        data.push_back(std::make_shared<PostRiserUs2O0J22<TypeRiserUs2O0Step>>(sRiserUs2O0Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
