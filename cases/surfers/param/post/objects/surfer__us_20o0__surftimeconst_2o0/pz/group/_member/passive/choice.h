#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_2O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_20O0__SURFTIMECONST_2O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_20o0__surftimeconst_2o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs20O0Surftimeconst2O0Step>
    using PostSurferUs20O0Surftimeconst2O0PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs20O0Surftimeconst2O0PzGroupMemberPassivePositionParameters, TypeSurferUs20O0Surftimeconst2O0Step>;
}

#endif
