#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_6O0_VEL_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_6O0_VEL_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/flow_velocity/core.h"
#include "param/post/objects/surfer__vs_1o0__surftimeconst_6o0/vel/group/_member/passive/flow_velocity/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostSurferVs1O0Surftimeconst6O0VelGroupMemberPassive = PostPostPassiveFlowVelocity<PostSurferVs1O0Surftimeconst6O0VelGroupMemberPassiveFlowVelocityParameters, TypeObjectStep>;
}

#endif
