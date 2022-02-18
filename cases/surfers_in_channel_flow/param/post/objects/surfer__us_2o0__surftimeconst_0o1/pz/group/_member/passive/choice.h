#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O1_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMECONST_0O1_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_2o0__surftimeconst_0o1/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs2O0Surftimeconst0O1Step>
    using PostSurferUs2O0Surftimeconst0O1PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs2O0Surftimeconst0O1PzGroupMemberPassivePositionParameters, TypeSurferUs2O0Surftimeconst0O1Step>;
}

#endif