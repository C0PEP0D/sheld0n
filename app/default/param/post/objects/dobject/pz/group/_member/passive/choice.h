#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PZ_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/dobject/pz/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeDobjectStep>
    using PostDobjectPzGroupMemberPassive = PostPostPassivePosition<PostDobjectPzGroupMemberPassivePositionParameters, TypeDobjectStep>;
}

#endif
