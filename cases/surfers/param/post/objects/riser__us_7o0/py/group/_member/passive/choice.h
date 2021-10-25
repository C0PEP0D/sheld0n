#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_7O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_7O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_7o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs7O0Step>
    using PostRiserUs7O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs7O0PyGroupMemberPassivePositionParameters, TypeRiserUs7O0Step>;
}

#endif
