#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_PARAMETERS_H
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
#include "param/post/objects/object/px/choice.h"
#include "param/post/objects/object/py/choice.h"
#include "param/post/objects/object/pz/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// Object post processing parameters
template<typename TypeObjectStep>
struct PostObjectParameters {
    std::string name = "object";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostObjectParameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostObjectPx<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostObjectPy<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostObjectPz<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
