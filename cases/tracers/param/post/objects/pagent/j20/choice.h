#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_J20_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_J20_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post processing
#include "param/post/objects/pagent/j20/group/choice.h"

namespace c0p {
    template<typename TypePagentStep>
    using PostPagentJ20 = PostPagentJ20Group<TypePagentStep>;
}

#endif
