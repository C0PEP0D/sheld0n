#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_2O25_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_2O25_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_2o25/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs2O0Surftimeprefactor2O25Step>
    using PostSurferUs2O0Surftimeprefactor2O25PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs2O0Surftimeprefactor2O25PzGroupMemberPassivePositionParameters, TypeSurferUs2O0Surftimeprefactor2O25Step>;
}

#endif