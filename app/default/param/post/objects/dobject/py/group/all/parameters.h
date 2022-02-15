#ifndef C0P_PARAM_POST_OBJECTS_DOBJECT_PY_GROUP_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_DOBJECT_PY_GROUP_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/group/all/prop.h"

// post member choice
#include "param/post/objects/dobject/py/group/_member/choice.h"

namespace c0p {

struct PostDobjectPyGroupAllParameters {
    template<typename TypeMemberStep>
    using TypePostPostMember = PostDobjectPyGroupMember<TypeMemberStep>;
};

}

#endif
