#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_3O25_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_3O25_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeprefactor_3o25/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeprefactor3O25Step>
    using PostSurferUs1O0Surftimeprefactor3O25PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs1O0Surftimeprefactor3O25PzGroupMemberPassivePositionParameters, TypeSurferUs1O0Surftimeprefactor3O25Step>;
}

#endif
