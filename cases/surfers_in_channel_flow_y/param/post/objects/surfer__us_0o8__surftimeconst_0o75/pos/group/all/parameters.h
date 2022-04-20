#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O8__SURFTIMECONST_0O75_POS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O8__SURFTIMECONST_0O75_POS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_0o8__surftimeconst_0o75/pos/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs0O8Surftimeconst0O75PosGroupAllParameters {
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostSurferUs0O8Surftimeconst0O75PosGroupMember<TypeMemberStep>;
};

}

#endif
