#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_20O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_20O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/riser__us_20o0/pz/group/_member/choice.h"

namespace c0p {

struct PostRiserUs20O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostRiserUs20O0PzGroupMember<TypeMemberStep>;
};

}

#endif
