#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_PARAMETERS_H
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
#include "param/post/objects/tracers/px/choice.h"
#include "param/post/objects/tracers/py/choice.h"
#include "param/post/objects/tracers/pz/choice.h"
#include "param/post/objects/tracers/j00/choice.h"
#include "param/post/objects/tracers/ux/choice.h"
#include "param/post/objects/tracers/uy/choice.h"
#include "param/post/objects/tracers/uz/choice.h"
#include "param/post/objects/tracers/j01/choice.h"
#include "param/post/objects/tracers/j02/choice.h"
#include "param/post/objects/tracers/j10/choice.h"
#include "param/post/objects/tracers/j11/choice.h"
#include "param/post/objects/tracers/j12/choice.h"
#include "param/post/objects/tracers/j20/choice.h"
#include "param/post/objects/tracers/j21/choice.h"
#include "param/post/objects/tracers/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// Tracers post processing parameters
template<typename TypeTracersStep>
struct PostTracersParameters {
    std::string name = "tracers";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypeTracersStep>>> data;
    PostTracersParameters(std::shared_ptr<TypeTracersStep> sTracersStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostTracersPx<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersPy<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersPz<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ00<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersUx<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersUy<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersUz<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ01<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ02<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ10<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ11<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ12<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ20<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ21<TypeTracersStep>>(sTracersStep));
        data.push_back(std::make_shared<PostTracersJ22<TypeTracersStep>>(sTracersStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
