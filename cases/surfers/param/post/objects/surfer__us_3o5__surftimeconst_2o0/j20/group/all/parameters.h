#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_J20_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_J20_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/surfer__us_3o5__surftimeconst_2o0/j20/group/_member/choice.h"

namespace c0p {

// Group post processing parameters
struct PostSurferUs3O5Surftimeconst2O0J20GroupAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeMemberStep>
    using TypePostPostMember = PostSurferUs3O5Surftimeconst2O0J20GroupMember<TypeMemberStep>;
};

}

#endif
