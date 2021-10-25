#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_1O5_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_1O5_PARAMETERS_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// COPY/REMOVE COMMAND ARE USED

// std include
#include <memory> // shared_ptr
#include <vector>
#include <string>
// app include
#include "core/init/objects/object/init/core.h"
// FLAG: INCLUDE INIT BEGIN
#include "param/init/objects/riser__us_1o5/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeRiserUs1O5Step>
struct InitRiserUs1O5Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeRiserUs1O5Step>>> data;
    InitRiserUs1O5Parameters(std::shared_ptr<TypeRiserUs1O5Step> sRiserUs1O5Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitRiserUs1O5Pos<TypeRiserUs1O5Step>>(sRiserUs1O5Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
