#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O05_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_0O05_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_0o05/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeconst0O05Step>
    using PostSurferUs1O0Surftimeconst0O05PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs1O0Surftimeconst0O05PzGroupMemberPassivePositionParameters, TypeSurferUs1O0Surftimeconst0O05Step>;
}

#endif
