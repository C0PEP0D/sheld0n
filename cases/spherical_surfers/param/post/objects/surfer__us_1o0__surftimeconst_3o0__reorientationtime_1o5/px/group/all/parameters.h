#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_3O0__REORIENTATIONTIME_1O5_PX_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_3O0__REORIENTATIONTIME_1O5_PX_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_1o0__surftimeconst_3o0__reorientationtime_1o5/px/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs1O0Surftimeconst3O0Reorientationtime1O5PxGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs1O0Surftimeconst3O0Reorientationtime1O5PxGroupMember<TypeMemberStep>;
};

}

#endif
