#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_2o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs2O0Step>
    using PostRiserUs2O0Py = PostPostGroupAll<PostRiserUs2O0PyGroupAllParameters, TypeRiserUs2O0Step>;
}

#endif
