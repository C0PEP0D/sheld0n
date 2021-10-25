#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_3o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs3O0Step>
    using PostRiserUs3O0Py = PostPostGroupAll<PostRiserUs3O0PyGroupAllParameters, TypeRiserUs3O0Step>;
}

#endif
