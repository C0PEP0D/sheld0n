#ifndef C0P_PARAM_INIT_OBJECTS_MOBJECT_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_MOBJECT_PARAMETERS_H
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
#include "param/init/objects/mobject/nb/choice.h"
#include "param/init/objects/mobject/pos/choice.h"
#include "param/init/objects/mobject/orient/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeObjectStep>
struct InitMobjectParameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<InitInitInitManager<TypeObjectStep>>> sInits;
    InitMobjectParameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitMobjectNb<TypeObjectStep>>(sObjectStep));
        sInits.push_back(std::make_shared<InitMobjectPos<TypeObjectStep>>(sObjectStep));
        sInits.push_back(std::make_shared<InitMobjectOrient<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
