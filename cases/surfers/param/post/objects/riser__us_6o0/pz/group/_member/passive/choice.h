#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_6o0/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs6O0Step>
    using PostRiserUs6O0PzGroupMemberPassive = PostPostPassivePosition<PostRiserUs6O0PzGroupMemberPassivePositionParameters, TypeRiserUs6O0Step>;
}

#endif
