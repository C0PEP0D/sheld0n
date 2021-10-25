#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_8O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_8O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_8o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs8O0Step>
    using PostRiserUs8O0Pz = PostPostGroupAll<PostRiserUs8O0PzGroupAllParameters, TypeRiserUs8O0Step>;
}

#endif
