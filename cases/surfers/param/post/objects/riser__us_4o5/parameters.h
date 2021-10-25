#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O5_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O5_PARAMETERS_H
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
#include "param/post/objects/riser__us_4o5/px/choice.h"
#include "param/post/objects/riser__us_4o5/py/choice.h"
#include "param/post/objects/riser__us_4o5/pz/choice.h"
#include "param/post/objects/riser__us_4o5/j00/choice.h"
#include "param/post/objects/riser__us_4o5/j01/choice.h"
#include "param/post/objects/riser__us_4o5/j02/choice.h"
#include "param/post/objects/riser__us_4o5/j10/choice.h"
#include "param/post/objects/riser__us_4o5/j11/choice.h"
#include "param/post/objects/riser__us_4o5/j12/choice.h"
#include "param/post/objects/riser__us_4o5/j20/choice.h"
#include "param/post/objects/riser__us_4o5/j21/choice.h"
#include "param/post/objects/riser__us_4o5/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// RiserUs4O5 post processing parameters
template<typename TypeRiserUs4O5Step>
struct PostRiserUs4O5Parameters {
    std::string name = "riser__us_4o5";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeRiserUs4O5Step>>> data;
    PostRiserUs4O5Parameters(std::shared_ptr<TypeRiserUs4O5Step> sRiserUs4O5Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostRiserUs4O5Px<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5Py<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5Pz<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J00<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J01<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J02<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J10<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J11<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J12<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J20<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J21<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        data.push_back(std::make_shared<PostRiserUs4O5J22<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
