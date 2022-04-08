#ifndef C0P_PARAM_INIT_OBJECTS_TRACERS__E1_0O1_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_TRACERS__E1_0O1_PARAMETERS_H
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
#include "param/init/objects/tracers__e1_0o1/pos_a/choice.h"
#include "param/init/objects/tracers__e1_0o1/pos_b/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeObjectStep>
struct InitTracersE10O1Parameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitStatic<TypeObjectStep>>> sInits;
    InitTracersE10O1Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitTracersE10O1PosA<TypeObjectStep>>(sObjectStep));
        sInits.push_back(std::make_shared<InitTracersE10O1PosB<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
