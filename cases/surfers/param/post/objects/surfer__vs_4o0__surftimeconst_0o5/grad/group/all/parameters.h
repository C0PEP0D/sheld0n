#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_0O5_GRAD_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_0O5_GRAD_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__vs_4o0__surftimeconst_0o5/grad/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferVs4O0Surftimeconst0O5GradGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferVs4O0Surftimeconst0O5GradGroupMember<TypeMemberStep>;
};

}

#endif
