#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_9O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_9O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_9o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs9O0Step>
    using PostRiserUs9O0Pz = PostPostGroupAll<PostRiserUs9O0PzGroupAllParameters, TypeRiserUs9O0Step>;
}

#endif
