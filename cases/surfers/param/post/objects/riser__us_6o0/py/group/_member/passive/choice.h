#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_6O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_6o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs6O0Step>
    using PostRiserUs6O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs6O0PyGroupMemberPassivePositionParameters, TypeRiserUs6O0Step>;
}

#endif
