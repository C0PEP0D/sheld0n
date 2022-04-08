#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O1_GRADS_GROUP_MEMBER_PAIR_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O1_GRADS_GROUP_MEMBER_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/pair/both/core.h"
#include "param/post/objects/tracers__e3_0o1/grads/group/_member/pair/both/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE30O1GradsGroupMemberPair = PostPostPairBoth<PostTracersE30O1GradsGroupMemberPairBothParameters, TypeObjectStep>;
}

#endif
