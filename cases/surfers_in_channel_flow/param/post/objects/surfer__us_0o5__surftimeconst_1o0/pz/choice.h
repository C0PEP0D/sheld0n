#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_1O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMECONST_1O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_0o5__surftimeconst_1o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs0O5Surftimeconst1O0Step>
    using PostSurferUs0O5Surftimeconst1O0Pz = PostPostGroupAll<PostSurferUs0O5Surftimeconst1O0PzGroupAllParameters, TypeSurferUs0O5Surftimeconst1O0Step>;
}

#endif