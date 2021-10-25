#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_1o5/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs1O5Step>
    using PostRiserUs1O5PzGroupMemberPassive = PostPostPassivePosition<PostRiserUs1O5PzGroupMemberPassivePositionParameters, TypeRiserUs1O5Step>;
}

#endif
