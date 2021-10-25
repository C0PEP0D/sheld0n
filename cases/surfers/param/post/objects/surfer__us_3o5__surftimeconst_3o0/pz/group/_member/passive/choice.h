#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_3O5__SURFTIMECONST_3O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_3O5__SURFTIMECONST_3O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_3o5__surftimeconst_3o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs3O5Surftimeconst3O0Step>
    using PostSurferUs3O5Surftimeconst3O0PzGroupMemberPassive = PostPostPassivePosition<PostSurferUs3O5Surftimeconst3O0PzGroupMemberPassivePositionParameters, TypeSurferUs3O5Surftimeconst3O0Step>;
}

#endif
