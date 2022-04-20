#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_3O0_POS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_3O0_POS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_0o2__surftimeprefactor_3o0/pos/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs0O2Surftimeprefactor3O0PosGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferUs0O2Surftimeprefactor3O0PosGroupMember<TypeMemberStep>;
};

}

#endif
