#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/pagent/py/group/all/parameters.h"
namespace c0p {
    template<typename TypePagentStep>
    using PostPagentPy = PostPostGroupAll<PostPagentPyGroupAllParameters, TypePagentStep>;
}

#endif
