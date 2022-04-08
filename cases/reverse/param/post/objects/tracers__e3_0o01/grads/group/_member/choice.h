#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O01_GRADS_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O01_GRADS_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "param/post/objects/tracers__e3_0o01/grads/group/_member/pair/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostTracersE30O01GradsGroupMember = PostTracersE30O01GradsGroupMemberPair<TypeMemberStep>;
}

#endif
