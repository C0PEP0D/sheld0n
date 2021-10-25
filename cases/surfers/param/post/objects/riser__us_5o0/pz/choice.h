#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_5O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_5O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_5o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs5O0Step>
    using PostRiserUs5O0Pz = PostPostGroupAll<PostRiserUs5O0PzGroupAllParameters, TypeRiserUs5O0Step>;
}

#endif
