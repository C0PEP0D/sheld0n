#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_10o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs10O0Step>
    using PostRiserUs10O0Py = PostPostGroupAll<PostRiserUs10O0PyGroupAllParameters, TypeRiserUs10O0Step>;
}

#endif
