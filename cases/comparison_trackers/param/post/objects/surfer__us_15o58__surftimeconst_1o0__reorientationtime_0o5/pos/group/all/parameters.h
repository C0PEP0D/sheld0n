#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_15O58__SURFTIMECONST_1O0__REORIENTATIONTIME_0O5_POS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_15O58__SURFTIMECONST_1O0__REORIENTATIONTIME_0O5_POS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_15o58__surftimeconst_1o0__reorientationtime_0o5/pos/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs15O58Surftimeconst1O0Reorientationtime0O5PosGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferUs15O58Surftimeconst1O0Reorientationtime0O5PosGroupMember<TypeMemberStep>;
};

}

#endif
