#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_4O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_4O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_4o5/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs4O5Step>
    using PostRiserUs4O5PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs4O5PyGroupMemberPassivePositionParameters, TypeRiserUs4O5Step>;
}

#endif
