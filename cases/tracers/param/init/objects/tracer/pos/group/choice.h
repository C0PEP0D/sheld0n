#ifndef C0P_PARAM_INIT_OBJECTS_TRACER_POS_GROUP_CHOICE_H
#define C0P_PARAM_INIT_OBJECTS_TRACER_POS_GROUP_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// member
#include "param/init/objects/tracer/pos/group/_member/choice.h"
// choose your init
#include "core/init/objects/object/init/group/all/core.h"
#include "param/init/objects/tracer/pos/group/all/parameters.h"

namespace c0p {
    template<typename TypeObjectStep>
    using InitTracerPosGroup = InitInitGroupAll<InitTracerPosGroupAllParameters, TypeObjectStep, InitTracerPosGroupMember>;
}

#endif
