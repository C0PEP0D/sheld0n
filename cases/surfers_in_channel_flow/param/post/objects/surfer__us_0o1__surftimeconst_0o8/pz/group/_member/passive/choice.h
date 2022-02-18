#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O8_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O1__SURFTIMECONST_0O8_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_0o1__surftimeconst_0o8/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O1Surftimeconst0O8Step>
    using PostSurferUs0O1Surftimeconst0O8PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs0O1Surftimeconst0O8PzGroupMemberPassivePositionParameters, TypeSurferUs0O1Surftimeconst0O8Step>;
}

#endif