#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PARAMETERS_H
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
#include "param/post/objects/dobject/px/choice.h"
#include "param/post/objects/dobject/py/choice.h"
#include "param/post/objects/dobject/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// Dobject post processing parameters
template<typename TypeDobjectStep>
struct PostDobjectParameters {
    std::string name = "dobject";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeDobjectStep>>> data;
    PostDobjectParameters(std::shared_ptr<TypeDobjectStep> sDobjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostDobjectPx<TypeDobjectStep>>(sDobjectStep));
        data.push_back(std::make_shared<PostDobjectPy<TypeDobjectStep>>(sDobjectStep));
        data.push_back(std::make_shared<PostDobjectPz<TypeDobjectStep>>(sDobjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
