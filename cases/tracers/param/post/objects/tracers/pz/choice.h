#ifndef C0P_PARAM_POST_OBJECTS_TRACERS_PZ_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS_PZ_CHOICE_H
#pragma once

// choose your post processing
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/tracers/pz/group/all/parameters.h"
namespace c0p {
    template<typename TypeTracersStep>
    using PostTracersPz = PostPostGroupAll<PostTracersPzGroupAllParameters, TypeTracersStep>;
}

#endif
