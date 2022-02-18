#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_3O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_3O0_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_3o0/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O5Surftimeprefactor3O0Step>
    using PostSurferUs0O5Surftimeprefactor3O0PyGroupMemberPassive = PostPostPassivePosition<PostSurferUs0O5Surftimeprefactor3O0PyGroupMemberPassivePositionParameters, TypeSurferUs0O5Surftimeprefactor3O0Step>;
}

#endif