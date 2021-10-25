#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_1O5_J00_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_1O5_J00_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/riser__us_1o5/j00/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostRiserUs1O5J00GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostRiserUs1O5J00GroupMember<TypeMemberStep>;
};

}

#endif
