#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_1o5/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs1O5Step>
    using PostRiserUs1O5Pz = PostPostGroupAll<PostRiserUs1O5PzGroupAllParameters, TypeRiserUs1O5Step>;
}

#endif
