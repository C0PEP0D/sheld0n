#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_0O5_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_0O5_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_0o5/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs0O5Step>
    using PostRiserUs0O5Py = PostPostGroupAll<PostRiserUs0O5PyGroupAllParameters, TypeRiserUs0O5Step>;
}

#endif
