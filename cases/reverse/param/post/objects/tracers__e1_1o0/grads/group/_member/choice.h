#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E1_1O0_GRADS_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E1_1O0_GRADS_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "param/post/objects/tracers__e1_1o0/grads/group/_member/pair/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostTracersE11O0GradsGroupMember = PostTracersE11O0GradsGroupMemberPair<TypeMemberStep>;
}

#endif
