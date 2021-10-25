#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_7O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_7O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_7o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs7O0Step>
    using PostRiserUs7O0Pz = PostPostGroupAll<PostRiserUs7O0PzGroupAllParameters, TypeRiserUs7O0Step>;
}

#endif
