#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O5_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O5_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_2o5/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs2O5Step>
    using PostRiserUs2O5Py = PostPostGroupAll<PostRiserUs2O5PyGroupAllParameters, TypeRiserUs2O5Step>;
}

#endif
