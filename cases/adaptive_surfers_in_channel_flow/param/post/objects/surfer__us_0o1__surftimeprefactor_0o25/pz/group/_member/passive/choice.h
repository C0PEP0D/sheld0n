#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_0O25_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_0O25_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_0o1__surftimeprefactor_0o25/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O1Surftimeprefactor0O25Step>
    using PostSurferUs0O1Surftimeprefactor0O25PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs0O1Surftimeprefactor0O25PzGroupMemberPassivePositionParameters, TypeSurferUs0O1Surftimeprefactor0O25Step>;
}

#endif
