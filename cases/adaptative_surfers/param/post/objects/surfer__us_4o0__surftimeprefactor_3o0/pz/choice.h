#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_3O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_3O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_4o0__surftimeprefactor_3o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs4O0Surftimeprefactor3O0Step>
    using PostSurferUs4O0Surftimeprefactor3O0Pz = PostPostGroupAll<PostSurferUs4O0Surftimeprefactor3O0PzGroupAllParameters, TypeSurferUs4O0Surftimeprefactor3O0Step>;
}

#endif
