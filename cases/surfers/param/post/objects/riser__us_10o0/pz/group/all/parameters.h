#ifndef C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PZ_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_RISER__US_10O0_PZ_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/riser__us_10o0/pz/group/_member/choice.h"

namespace c0p {

struct PostRiserUs10O0PzGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostRiserUs10O0PzGroupMember<TypeMemberStep>;
};

}

#endif
