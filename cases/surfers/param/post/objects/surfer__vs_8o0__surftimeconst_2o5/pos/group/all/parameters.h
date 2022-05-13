#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_2O5_POS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_2O5_POS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__vs_8o0__surftimeconst_2o5/pos/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferVs8O0Surftimeconst2O5PosGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferVs8O0Surftimeconst2O5PosGroupMember<TypeMemberStep>;
};

}

#endif
