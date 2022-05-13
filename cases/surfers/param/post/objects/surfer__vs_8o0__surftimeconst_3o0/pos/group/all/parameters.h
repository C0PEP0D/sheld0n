#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_3O0_POS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_3O0_POS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__vs_8o0__surftimeconst_3o0/pos/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferVs8O0Surftimeconst3O0PosGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferVs8O0Surftimeconst3O0PosGroupMember<TypeMemberStep>;
};

}

#endif
