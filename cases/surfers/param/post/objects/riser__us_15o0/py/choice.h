#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_15O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_15O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_15o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs15O0Step>
    using PostRiserUs15O0Py = PostPostGroupAll<PostRiserUs15O0PyGroupAllParameters, TypeRiserUs15O0Step>;
}

#endif
