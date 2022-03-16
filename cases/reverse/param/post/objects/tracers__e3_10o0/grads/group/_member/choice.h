#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_GRADS_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_10O0_GRADS_GROUP_MEMBER_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your post
#include "param/post/objects/tracers__e3_10o0/grads/group/_member/pair/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostTracersE310O0GradsGroupMember = PostTracersE310O0GradsGroupMemberPair<TypeMemberStep>;
}

#endif
