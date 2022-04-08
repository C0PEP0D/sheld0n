#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E1_0O1_GRADS_GROUP_MEMBER_PAIR_BOTH_A_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E1_0O1_GRADS_GROUP_MEMBER_PAIR_BOTH_A_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/flow_gradients/core.h"
#include "param/post/objects/tracers__e1_0o1/grads/group/_member/pair/both/_a/passive/flow_gradients/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE10O1GradsGroupMemberPairBothAPassive = PostPostPassiveFlowGradients<PostTracersE10O1GradsGroupMemberPairBothAPassiveFlowGradientsParameters, TypeObjectStep>;
}

#endif
