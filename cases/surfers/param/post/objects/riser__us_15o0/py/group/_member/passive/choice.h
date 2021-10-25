#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_15O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_15O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_15o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs15O0Step>
    using PostRiserUs15O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs15O0PyGroupMemberPassivePositionParameters, TypeRiserUs15O0Step>;
}

#endif
