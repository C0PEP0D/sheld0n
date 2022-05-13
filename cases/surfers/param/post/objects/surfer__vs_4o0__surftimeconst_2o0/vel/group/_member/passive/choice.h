#ifndef C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_2O0_VEL_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_2O0_VEL_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "core/post/objects/object/post/passive/flow_velocity/core.h"
#include "param/post/objects/surfer__vs_4o0__surftimeconst_2o0/vel/group/_member/passive/flow_velocity/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostSurferVs4O0Surftimeconst2O0VelGroupMemberPassive = PostPostPassiveFlowVelocity<PostSurferVs4O0Surftimeconst2O0VelGroupMemberPassiveFlowVelocityParameters, TypeObjectStep>;
}

#endif
