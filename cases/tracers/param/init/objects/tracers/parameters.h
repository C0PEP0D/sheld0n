#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS_PARAMETERS_H
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
#include "param/init/objects/tracers/pos/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeTracersStep>
struct InitTracersParameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInit<TypeTracersStep>>> data;
    InitTracersParameters(std::shared_ptr<TypeTracersStep> sTracersStep) {
        // FLAG: MAKE INIT BEGIN
        data.push_back(std::make_shared<InitTracersPos<TypeTracersStep>>(sTracersStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
