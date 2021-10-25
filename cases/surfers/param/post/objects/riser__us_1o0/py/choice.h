#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_1o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs1O0Step>
    using PostRiserUs1O0Py = PostPostGroupAll<PostRiserUs1O0PyGroupAllParameters, TypeRiserUs1O0Step>;
}

#endif
