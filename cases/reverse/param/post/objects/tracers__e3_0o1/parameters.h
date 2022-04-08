#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O1_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O1_PARAMETERS_H
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
#include "param/post/objects/tracers__e3_0o1/pos/choice.h"
#include "param/post/objects/tracers__e3_0o1/grads/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// TracersE30O1 post processing parameters
template<typename TypeObjectStep>
struct PostTracersE30O1Parameters {
    std::string name = "tracers__e3_0o1";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeObjectStep>>> data;
    PostTracersE30O1Parameters(std::shared_ptr<TypeObjectStep> sObjectStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostTracersE30O1Pos<TypeObjectStep>>(sObjectStep));
        data.push_back(std::make_shared<PostTracersE30O1Grads<TypeObjectStep>>(sObjectStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
