#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_15O58__SURFTIMECONST_10O0__REORIENTATIONTIME_0O5_PX_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_15O58__SURFTIMECONST_10O0__REORIENTATIONTIME_0O5_PX_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_15o58__surftimeconst_10o0__reorientationtime_0o5/px/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs15O58Surftimeconst10O0Reorientationtime0O5PxGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs15O58Surftimeconst10O0Reorientationtime0O5PxGroupMember<TypeMemberStep>;
};

}

#endif
