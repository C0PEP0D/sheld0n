#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_10o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs10O0Step>
    using PostRiserUs10O0Pz = PostPostGroupAll<PostRiserUs10O0PzGroupAllParameters, TypeRiserUs10O0Step>;
}

#endif
