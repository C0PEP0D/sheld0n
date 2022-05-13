#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_1O0_VEL_GROUP_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_1O0_VEL_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/group/all/core.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_1o0/vel/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostSurferVs1O0Surftimeconst1O0VelGroup = PostPostGroupAll<PostSurferVs1O0Surftimeconst1O0VelGroupAllParameters, TypeObjectStep>;
}

#endif