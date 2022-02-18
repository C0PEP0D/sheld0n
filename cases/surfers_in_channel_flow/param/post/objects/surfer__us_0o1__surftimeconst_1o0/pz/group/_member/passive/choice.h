#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_1O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_1O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_1o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O1Surftimeconst1O0Step>
    using PostSurferUs0O1Surftimeconst1O0PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs0O1Surftimeconst1O0PzGroupMemberPassivePositionParameters, TypeSurferUs0O1Surftimeconst1O0Step>;
}

#endif