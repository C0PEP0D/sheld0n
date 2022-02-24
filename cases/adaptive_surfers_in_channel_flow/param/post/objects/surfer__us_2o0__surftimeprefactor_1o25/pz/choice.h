#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O25_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O25_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o25/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs2O0Surftimeprefactor1O25Step>
    using PostSurferUs2O0Surftimeprefactor1O25Pz = PostPostGroupAll<PostSurferUs2O0Surftimeprefactor1O25PzGroupAllParameters, TypeSurferUs2O0Surftimeprefactor1O25Step>;
}

#endif
