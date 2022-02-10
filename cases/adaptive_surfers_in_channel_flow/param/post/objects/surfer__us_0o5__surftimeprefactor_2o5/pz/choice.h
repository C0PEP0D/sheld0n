#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O5_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O5_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_2o5/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs0O5Surftimeprefactor2O5Step>
    using PostSurferUs0O5Surftimeprefactor2O5Pz = PostPostGroupAll<PostSurferUs0O5Surftimeprefactor2O5PzGroupAllParameters, TypeSurferUs0O5Surftimeprefactor2O5Step>;
}

#endif
