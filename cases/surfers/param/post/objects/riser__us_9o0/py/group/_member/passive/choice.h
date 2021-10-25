#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_9O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_9O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_9o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs9O0Step>
    using PostRiserUs9O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs9O0PyGroupMemberPassivePositionParameters, TypeRiserUs9O0Step>;
}

#endif
