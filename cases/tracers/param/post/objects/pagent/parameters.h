#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_PARAMETERS_H
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
#include "param/post/objects/pagent/px/choice.h"
#include "param/post/objects/pagent/py/choice.h"
#include "param/post/objects/pagent/pz/choice.h"
#include "param/post/objects/pagent/ux/choice.h"
#include "param/post/objects/pagent/j00/choice.h"
#include "param/post/objects/pagent/uy/choice.h"
#include "param/post/objects/pagent/uz/choice.h"
#include "param/post/objects/pagent/j01/choice.h"
#include "param/post/objects/pagent/j02/choice.h"
#include "param/post/objects/pagent/j10/choice.h"
#include "param/post/objects/pagent/j11/choice.h"
#include "param/post/objects/pagent/j12/choice.h"
#include "param/post/objects/pagent/j20/choice.h"
#include "param/post/objects/pagent/j21/choice.h"
#include "param/post/objects/pagent/j22/choice.h"
// FLAG: INCLUDE POST END

namespace c0p {

// Pagent post processing parameters
template<typename TypePagentStep>
struct PostPagentParameters {
    std::string name = "pagent";
    // make data
    std::vector<std::shared_ptr<PostPostPost<TypePagentStep>>> data;
    PostPagentParameters(std::shared_ptr<TypePagentStep> sPagentStep) {
        // FLAG: MAKE POST BEGIN
        data.push_back(std::make_shared<PostPagentPx<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentPy<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentPz<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentUx<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ00<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentUy<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentUz<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ01<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ02<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ10<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ11<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ12<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ20<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ21<TypePagentStep>>(sPagentStep));
        data.push_back(std::make_shared<PostPagentJ22<TypePagentStep>>(sPagentStep));
        // FLAG: MAKE POST END
    }
};

}

#endif
