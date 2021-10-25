#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PARAMETERS_H
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
#include "param/post/objects/riser__us_1o5/px/choice.h"
#include "param/post/objects/riser__us_1o5/py/choice.h"
#include "param/post/objects/riser__us_1o5/pz/choice.h"
#include "param/post/objects/riser__us_1o5/j00/choice.h"
#include "param/post/objects/riser__us_1o5/j01/choice.h"
#include "param/post/objects/riser__us_1o5/j02/choice.h"
#include "param/post/objects/riser__us_1o5/j10/choice.h"
#include "param/post/objects/riser__us_1o5/j11/choice.h"
#include "param/post/objects/riser__us_1o5/j12/choice.h"
#include "param/post/objects/riser__us_1o5/j20/choice.h"
#include "param/post/objects/riser__us_1o5/j21/choice.h"
#include "param/post/objects/riser__us_1o5/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// RiserUs1O5 post processing parameters
template<typename TypeRiserUs1O5Step>
struct PostRiserUs1O5Parameters {
    std::string name = "riser__us_1o5";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeRiserUs1O5Step>>> data;
    PostRiserUs1O5Parameters(std::shared_ptr<TypeRiserUs1O5Step> sRiserUs1O5Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostRiserUs1O5Px<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5Py<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5Pz<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J00<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J01<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J02<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J10<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J11<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J12<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J20<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J21<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        data.push_back(std::make_shared<PostRiserUs1O5J22<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
