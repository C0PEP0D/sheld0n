#ifndef C0P_PARAM_INIT_OBJECTS_DOBJECT_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_DOBJECT_PARAMETERS_H
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
// dynamic init
#include "param/init/objects/dobject/nb/choice.h"
// FLAG: INCLUDE INIT BEGIN
#include "param/init/objects/dobject/pos/choice.h"
#include "param/init/objects/dobject/orient/choice.h"
// FLAG: INCLUDE INIT END

namespace c0p {

template<typename TypeDobjectStep>
struct InitDobjectParameters {
    std::string name = "object";
    // make data
    std::shared_ptr<InitInitInitDynamic<TypeDobjectStep>> sDynamicInit; 
    std::vector<std::shared_ptr<InitInitInitStatic<TypeDobjectStep>>> sInits;
    InitDobjectParameters(std::shared_ptr<TypeDobjectStep> sDobjectStep) {
    	// dynamic init
    	sDynamicInit = std::make_shared<InitDobjectNb<TypeDobjectStep>>(sDobjectStep);
        // FLAG: MAKE INIT BEGIN
        sInits.push_back(std::make_shared<InitDobjectPos<TypeDobjectStep>>(sDobjectStep));
        sInits.push_back(std::make_shared<InitDobjectOrient<TypeDobjectStep>>(sDobjectStep));
        // FLAG: MAKE INIT END
    }
};

}

#endif
