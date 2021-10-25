#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_4O5_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_4O5_PARAMETERS_H
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
#include "param/init/objects/riser__us_4o5/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeRiserUs4O5Step>
struct InitRiserUs4O5Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeRiserUs4O5Step>>> data;
    InitRiserUs4O5Parameters(std::shared_ptr<TypeRiserUs4O5Step> sRiserUs4O5Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitRiserUs4O5Pos<TypeRiserUs4O5Step>>(sRiserUs4O5Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
