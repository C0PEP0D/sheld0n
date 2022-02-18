#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_0o5__surftimeprefactor_2o5/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs0O5Surftimeprefactor2O5Step>
    using PostSurferUs0O5Surftimeprefactor2O5PyGroupMemberPassive = PostPostPassivePosition<PostSurferUs0O5Surftimeprefactor2O5PyGroupMemberPassivePositionParameters, TypeSurferUs0O5Surftimeprefactor2O5Step>;
}

#endif