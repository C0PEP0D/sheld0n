#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_6o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs6O0Step>
    using PostRiserUs6O0Pz = PostPostGroupAll<PostRiserUs6O0PzGroupAllParameters, TypeRiserUs6O0Step>;
}

#endif
