#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O5_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O5_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_3o5/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs3O5Step>
    using PostRiserUs3O5PzGroupMemberPassive = PostPostPassivePosition<PostRiserUs3O5PzGroupMemberPassivePositionParameters, TypeRiserUs3O5Step>;
}

#endif
