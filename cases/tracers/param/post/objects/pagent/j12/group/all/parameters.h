#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_J12_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_J12_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/pagent/j12/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostPagentJ12GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostPagentJ12GroupMember<TypeMemberStep>;
};

}

#endif
