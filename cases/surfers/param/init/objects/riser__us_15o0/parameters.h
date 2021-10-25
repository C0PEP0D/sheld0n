#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_15O0_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_15O0_PARAMETERS_H
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
#include "param/init/objects/riser__us_15o0/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeRiserUs15O0Step>
struct InitRiserUs15O0Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeRiserUs15O0Step>>> data;
    InitRiserUs15O0Parameters(std::shared_ptr<TypeRiserUs15O0Step> sRiserUs15O0Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitRiserUs15O0Pos<TypeRiserUs15O0Step>>(sRiserUs15O0Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
