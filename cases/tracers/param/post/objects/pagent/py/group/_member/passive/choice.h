#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/pagent/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypePagentStep>
    using PostPagentPyGroupMemberPassive = PostPostPassivePosition<PostPagentPyGroupMemberPassivePositionParameters, TypePagentStep>;
}

#endif
