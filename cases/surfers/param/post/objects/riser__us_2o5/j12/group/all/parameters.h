#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_2O5_J12_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_2O5_J12_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/riser__us_2o5/j12/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostRiserUs2O5J12GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostRiserUs2O5J12GroupMember<TypeMemberStep>;
};

}

#endif
