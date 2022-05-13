#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_6O0_GRAD_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_6O0_GRAD_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/flow_gradients/core.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_6o0/grad/group/_member/passive/flow_gradients/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostSurferVs4O0Surftimeconst6O0GradGroupMemberPassive = PostPostPassiveFlowGradients<PostSurferVs4O0Surftimeconst6O0GradGroupMemberPassiveFlowGradientsParameters, TypeObjectStep>;
}

#endif