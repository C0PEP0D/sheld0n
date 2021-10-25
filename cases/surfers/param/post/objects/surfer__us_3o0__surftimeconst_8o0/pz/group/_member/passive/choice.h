#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_3O0__SURFTIMECONST_8O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_3O0__SURFTIMECONST_8O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_3o0__surftimeconst_8o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs3O0Surftimeconst8O0Step>
    using PostSurferUs3O0Surftimeconst8O0PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs3O0Surftimeconst8O0PzGroupMemberPassivePositionParameters, TypeSurferUs3O0Surftimeconst8O0Step>;
}

#endif
