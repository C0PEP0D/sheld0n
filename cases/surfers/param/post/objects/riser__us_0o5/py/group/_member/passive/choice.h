#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_0O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_0O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_0o5/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs0O5Step>
    using PostRiserUs0O5PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs0O5PyGroupMemberPassivePositionParameters, TypeRiserUs0O5Step>;
}

#endif
