#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_2O0_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_2O0_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_2o0/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs0O1Surftimeprefactor2O0Step>
    using PostSurferUs0O1Surftimeprefactor2O0Pz = PostPostGroupAll<PostSurferUs0O1Surftimeprefactor2O0PzGroupAllParameters, TypeSurferUs0O1Surftimeprefactor2O0Step>;
}

#endif
