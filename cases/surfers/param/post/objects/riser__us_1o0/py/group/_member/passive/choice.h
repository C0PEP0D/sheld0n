#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_1o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs1O0Step>
    using PostRiserUs1O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs1O0PyGroupMemberPassivePositionParameters, TypeRiserUs1O0Step>;
}

#endif
