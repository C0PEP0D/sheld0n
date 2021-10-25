#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_3O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_3O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/riser__us_3o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeRiserUs3O0Step>
    using PostRiserUs3O0PyGroupMemberPassive = PostPostPassivePosition<PostRiserUs3O0PyGroupMemberPassivePositionParameters, TypeRiserUs3O0Step>;
}

#endif
