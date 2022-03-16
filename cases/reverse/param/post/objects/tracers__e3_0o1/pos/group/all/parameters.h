#ifndef C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O1_POS_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_TRACERS__E3_0O1_POS_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/tracers__e3_0o1/pos/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostTracersE30O1PosGroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostTracersE30O1PosGroupMember<TypeMemberStep>;
};

}

#endif
