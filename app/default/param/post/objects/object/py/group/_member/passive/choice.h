#ifndef C0P_PARAM_POST_OBJECTS_OBJECT_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_OBJECT_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/object/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using PostObjectPyGroupMemberPassive = PostPostPassivePosition<PostObjectPyGroupMemberPassivePositionParameters, TypeObjectStep>;
}

#endif
