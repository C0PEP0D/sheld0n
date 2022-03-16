#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E2_0O1_GRADS_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E2_0O1_GRADS_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "param/post/objects/tracers__e2_0o1/grads/group/_member/pair/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostTracersE20O1GradsGroupMember = PostTracersE20O1GradsGroupMemberPair<TypeMemberStep>;
}

#endif
