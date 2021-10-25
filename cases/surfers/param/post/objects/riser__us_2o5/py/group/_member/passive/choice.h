#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_2o5/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs2O5Step>
    using PostRiserUs2O5PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs2O5PyGroupMemberPassivePositionParameters, TypeRiserUs2O5Step>;
}

#endif
