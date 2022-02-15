#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PY_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PY_GROUP_MEMBER_CHOICE_H
#pragma once

// choose your post
#include "param/post/objects/dobject/py/group/_member/passive/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostDobjectPyGroupMember = PostDobjectPyGroupMemberPassive<TypeMemberStep>;
}

#endif
