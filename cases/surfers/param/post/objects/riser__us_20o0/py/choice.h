#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_20O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_20O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_20o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs20O0Step>
    using PostRiserUs20O0Py = PostPostGroupAll<PostRiserUs20O0PyGroupAllParameters, TypeRiserUs20O0Step>;
}

#endif
