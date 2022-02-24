#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_0O75_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_0O75_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_0o75/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs0O1Surftimeprefactor0O75Step>
    using PostSurferUs0O1Surftimeprefactor0O75Pz = PostPostGroupAll<PostSurferUs0O1Surftimeprefactor0O75PzGroupAllParameters, TypeSurferUs0O1Surftimeprefactor0O75Step>;
}

#endif