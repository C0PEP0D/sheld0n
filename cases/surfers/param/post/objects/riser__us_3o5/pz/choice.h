#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O5_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O5_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/riser__us_3o5/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeRiserUs3O5Step>
    using PostRiserUs3O5Pz = PostPostGroupAll<PostRiserUs3O5PzGroupAllParameters, TypeRiserUs3O5Step>;
}

#endif
