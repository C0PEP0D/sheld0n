#ifndef C0P_PARAM_INIT_OBJECTS_RISER__US_3O5_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_RISER__US_3O5_PARAMETERS_H
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
#include "param/init/objects/riser__us_3o5/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeRiserUs3O5Step>
struct InitRiserUs3O5Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeRiserUs3O5Step>>> data;
    InitRiserUs3O5Parameters(std::shared_ptr<TypeRiserUs3O5Step> sRiserUs3O5Step) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitRiserUs3O5Pos<TypeRiserUs3O5Step>>(sRiserUs3O5Step));
        // FLAG: MAKE INIT END
    }
};

}

#endif
