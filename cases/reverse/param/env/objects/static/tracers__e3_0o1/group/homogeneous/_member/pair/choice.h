#ifndef C0P_PARAM_OBJECTS_TRACERS__E3_0O1_GROUP_HOMOGENEOUS_MEMBER_PAIR_CHOICE_H
#define C0P_PARAM_OBJECTS_TRACERS__E3_0O1_GROUP_HOMOGENEOUS_MEMBER_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "core/env/objects/object/pair/simple/core.h"
#include "param/env/objects/static/tracers__e3_0o1/group/homogeneous/_member/pair/simple/parameters.h"
#include "param/env/objects/static/tracers__e3_0o1/group/homogeneous/_member/pair/_a/choice.h"
#include "param/env/objects/static/tracers__e3_0o1/group/homogeneous/_member/pair/_b/choice.h"
namespace c0p {
    using TracersE30O1GroupHomogeneousMemberPairStep = PairSimpleStep<TracersE30O1GroupHomogeneousMemberPairSimpleStepParameters, TracersE30O1GroupHomogeneousMemberPairAStep, TracersE30O1GroupHomogeneousMemberPairBStep>;
}

#endif
