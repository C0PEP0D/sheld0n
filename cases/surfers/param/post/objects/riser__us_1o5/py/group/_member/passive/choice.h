#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_1o5/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs1O5Step>
    using PostRiserUs1O5PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs1O5PyGroupMemberPassivePositionParameters, TypeRiserUs1O5Step>;
}

#endif
