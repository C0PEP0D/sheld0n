#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_0O5_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_0O5_PARAMETERS_H
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
#include "param/post/objects/riser__us_0o5/px/choice.h"
#include "param/post/objects/riser__us_0o5/py/choice.h"
#include "param/post/objects/riser__us_0o5/pz/choice.h"
#include "param/post/objects/riser__us_0o5/j00/choice.h"
#include "param/post/objects/riser__us_0o5/j01/choice.h"
#include "param/post/objects/riser__us_0o5/j02/choice.h"
#include "param/post/objects/riser__us_0o5/j10/choice.h"
#include "param/post/objects/riser__us_0o5/j11/choice.h"
#include "param/post/objects/riser__us_0o5/j12/choice.h"
#include "param/post/objects/riser__us_0o5/j20/choice.h"
#include "param/post/objects/riser__us_0o5/j21/choice.h"
#include "param/post/objects/riser__us_0o5/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// RiserUs0O5 post processing parameters
template<typename TypeRiserUs0O5Step>
struct PostRiserUs0O5Parameters {
    std::string name = "riser__us_0o5";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeRiserUs0O5Step>>> data;
    PostRiserUs0O5Parameters(std::shared_ptr<TypeRiserUs0O5Step> sRiserUs0O5Step) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostRiserUs0O5Px<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5Py<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5Pz<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J00<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J01<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J02<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J10<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J11<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J12<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J20<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J21<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        data.push_back(std::make_shared<PostRiserUs0O5J22<TypeRiserUs0O5Step>>(sRiserUs0O5Step));
        // FLAG: MAKE POST END
    }
};

}

#endif
