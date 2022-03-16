#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E1_10O0_POS_GROUP_MEMBER_PAIR_BOTH_A_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E1_10O0_POS_GROUP_MEMBER_PAIR_BOTH_A_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/tracers__e1_10o0/pos/group/_member/pair/both/_a/passive/position/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE110O0PosGroupMemberPairBothAPassive = PostPostPassivePosition<PostTracersE110O0PosGroupMemberPairBothAPassivePositionParameters, TypeObjectStep>;
}

#endif
