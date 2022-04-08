#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_POS_CHAIN_VALUE_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_POS_CHAIN_VALUE_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/chain/value/prop.h"
// post member choice
#include "param/post/objects/dobject/pos/chain/value/_member/choice.h"

#include "param/parameters.h"

namespace c0p {

// Position post processing parameter
struct PostDobjectPosChainValueParameters {
	// Position along the chain.
	double dl = 0.01;
	// Specify the post processing to apply to group members.
	// This parameter should not be changed by the user.
	template<typename TypeMemberStep>
	using TypePostPostMember = PostDobjectPosChainValueMember<TypeMemberStep>;
};

}

#endif
