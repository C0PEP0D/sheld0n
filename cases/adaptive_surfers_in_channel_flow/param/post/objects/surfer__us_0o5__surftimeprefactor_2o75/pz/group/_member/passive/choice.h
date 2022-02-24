#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O75_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O75_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_2o75/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O5Surftimeprefactor2O75Step>
    using PostSurferUs0O5Surftimeprefactor2O75PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs0O5Surftimeprefactor2O75PzGroupMemberPassivePositionParameters, TypeSurferUs0O5Surftimeprefactor2O75Step>;
}

#endif