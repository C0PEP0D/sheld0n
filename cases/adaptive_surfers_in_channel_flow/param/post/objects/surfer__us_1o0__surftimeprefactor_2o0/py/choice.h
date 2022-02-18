#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_2O0_PY_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_2O0_PY_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o0/py/group/all/parameters.h"
namespace c0p {
    template<typename TypeSurferUs1O0Surftimeprefactor2O0Step>
    using PostSurferUs1O0Surftimeprefactor2O0Py = PostPostGroupAll<PostSurferUs1O0Surftimeprefactor2O0PyGroupAllParameters, TypeSurferUs1O0Surftimeprefactor2O0Step>;
}

#endif