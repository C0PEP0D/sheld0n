#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_1O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_1O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_1o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeprefactor1O0Step>
    using PostSurferUs1O0Surftimeprefactor1O0PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs1O0Surftimeprefactor1O0PzGroupMemberPassivePositionParameters, TypeSurferUs1O0Surftimeprefactor1O0Step>;
}

#endif
