#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O5_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O5_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_4o5/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs4O5Step>
    using PostRiserUs4O5Pz = PostPostGroupAll<PostRiserUs4O5PzGroupAllParameters, TypeRiserUs4O5Step>;
}

#endif
