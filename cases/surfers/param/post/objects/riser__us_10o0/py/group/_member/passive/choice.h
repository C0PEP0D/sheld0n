#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_10o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs10O0Step>
    using PostRiserUs10O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs10O0PyGroupMemberPassivePositionParameters, TypeRiserUs10O0Step>;
}

#endif
