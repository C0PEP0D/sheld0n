#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_PZ_GROUP_MEMBER_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_PZ_GROUP_MEMBER_CHOICE_H
#pragma once

// choose your post
#include "param/post/objects/pagent/pz/group/_member/passive/choice.h"

namespace c0p {
    template<typename TypeMemberStep>
    using PostPagentPzGroupMember = PostPagentPzGroupMemberPassive<TypeMemberStep>;
}

#endif
