#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_4O0_VEL_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_4O0_VEL_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__vs_1o0__surftimeconst_4o0/vel/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferVs1O0Surftimeconst4O0VelGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferVs1O0Surftimeconst4O0VelGroupMember<TypeMemberStep>;
};

}

#endif
