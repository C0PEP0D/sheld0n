#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_3O0__SURFTIMECONST_3O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_3O0__SURFTIMECONST_3O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_3o0__surftimeconst_3o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs3O0Surftimeconst3O0Step>
    using PostSurferUs3O0Surftimeconst3O0Pz = PostPostGroupAll<PostSurferUs3O0Surftimeconst3O0PzGroupAllParameters, TypeSurferUs3O0Surftimeconst3O0Step>;
}

#endif
