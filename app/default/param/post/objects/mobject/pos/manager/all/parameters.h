#ifndef C0P_PARAM_POST_OBJECTS_MOBJECT_POS_MANAGER_ALL_PARAMETERS_H
#define C0P_PARAM_POST_OBJECTS_MOBJECT_POS_MANAGER_ALL_PARAMETERS_H
#pragma once

// app include
#include "core/post/objects/object/post/manager/all/prop.h"

// post member choice
#include "param/post/objects/mobject/pos/manager/_managed/choice.h"

namespace c0p {

// Group post processing parameters
struct PostMobjectPosManagerAllParameters {
    // Specify the post processing to apply to group members.
    // This parameter should not be changed by the user.
    template<typename TypeManagedStep>
    using TypePostPostManaged = PostMobjectPosManagerManaged<TypeManagedStep>;
};

}

#endif
