#ifndef C0P_PARAM_POST_OBJECTS_TRACER_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACER_PARAMETERS_H
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
#include "param/post/objects/tracer/pos/choice.h"
#include "param/post/objects/tracer/grad/choice.h"
#include "param/post/objects/tracer/vel/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// Tracer post processing parameters
template<typename TypeObjectStep>
struct PostTracerParameters {
    std::string name = "tracer";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostTracerParameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostTracerPos<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostTracerGrad<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostTracerVel<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
