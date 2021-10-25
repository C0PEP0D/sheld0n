#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_2O75_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_2O75_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_2o75/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeprefactor2O75Step>
    using PostSurferUs1O0Surftimeprefactor2O75PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs1O0Surftimeprefactor2O75PzGroupMemberPassivePositionParameters, TypeSurferUs1O0Surftimeprefactor2O75Step>;
}

#endif
