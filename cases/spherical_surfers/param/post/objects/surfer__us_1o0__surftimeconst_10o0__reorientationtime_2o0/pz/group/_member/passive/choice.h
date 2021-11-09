#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_10O0__REORIENTATIONTIME_2O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_1O0__SURFTIMECONST_10O0__REORIENTATIONTIME_2O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_1o0__surftimeconst_10o0__reorientationtime_2o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs1O0Surftimeconst10O0Reorientationtime2O0Step>
    using PostSurferUs1O0Surftimeconst10O0Reorientationtime2O0PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs1O0Surftimeconst10O0Reorientationtime2O0PzGroupMemberPassivePositionParameters, TypeSurferUs1O0Surftimeconst10O0Reorientationtime2O0Step>;
}

#endif
