#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_4o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs4O0Step>
    using PostRiserUs4O0Pz = PostPostGroupAll<PostRiserUs4O0PzGroupAllParameters, TypeRiserUs4O0Step>;
}

#endif
