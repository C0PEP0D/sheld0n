#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_1O25_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_1O25_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o25/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs1O0Surftimeprefactor1O25Step>
    using PostSurferUs1O0Surftimeprefactor1O25Pz = PostPostGroupAll<PostSurferUs1O0Surftimeprefactor1O25PzGroupAllParameters, TypeSurferUs1O0Surftimeprefactor1O25Step>;
}

#endif