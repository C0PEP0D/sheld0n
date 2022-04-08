#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E2_10O0_GRADS_GROUP_MEMBER_PAIR_BOTH_B_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E2_10O0_GRADS_GROUP_MEMBER_PAIR_BOTH_B_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/flow_gradients/core.h"
#include "param/post/objects/tracers__e2_10o0/grads/group/_member/pair/both/_b/passive/flow_gradients/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostTracersE210O0GradsGroupMemberPairBothBPassive = PostPostPassiveFlowGradients<PostTracersE210O0GradsGroupMemberPairBothBPassiveFlowGradientsParameters, TypeObjectStep>;
}

#endif
