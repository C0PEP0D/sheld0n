#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_POS_GROUP_MEMBER_PAIR_BOTH_B_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_POS_GROUP_MEMBER_PAIR_BOTH_B_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/tracers__e3_10o0/pos/group/_member/pair/both/_b/passive/position/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE310O0PosGroupMemberPairBothBPassive = PostPostPassivePosition<PostTracersE310O0PosGroupMemberPairBothBPassivePositionParameters, TypeObjectStep>;
}

#endif
