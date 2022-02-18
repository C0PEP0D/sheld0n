#ifndef C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#define C0P_PARAM_POST_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O5_PY_GROUP_MEMBER_PASSIVE_CHOICE_H
#pragma once

// choose your post
#include "core/post/objects/object/post/passive/position/core.h"
#include "param/post/objects/surfer__us_2o0__surftimeprefactor_1o5/py/group/_member/passive/position/parameters.h"

namespace c0p {
    template<typename TypeSurferUs2O0Surftimeprefactor1O5Step>
    using PostSurferUs2O0Surftimeprefactor1O5PyGroupMemberPassive = PostPostPassivePosition<PostSurferUs2O0Surftimeprefactor1O5PyGroupMemberPassivePositionParameters, TypeSurferUs2O0Surftimeprefactor1O5Step>;
}

#endif