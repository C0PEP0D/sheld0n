#ifndef C0P_PARAM_POST_OBJECTS_PAGENT_PY_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_PAGENT_PY_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/pagent/py/group/_member/choice.h"

namespace c0p {

struct PostPagentPyGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostPagentPyGroupMember<TypeMemberStep>;
};

}

#endif
