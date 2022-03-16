#ifndef C0P_PARAM_OBJECTS_TRACERS__E2_0O01_GROUP_HOMOGENEOUS_MEMBER_PAIR_CHOICE_H
#define C0P_PARAM_OBJECTS_TRACERS__E2_0O01_GROUP_HOMOGENEOUS_MEMBER_PAIR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "core/env/objects/object/pair/simple/core.h"
#include "param/env/objects/static/tracers__e2_0o01/group/homogeneous/_member/pair/simple/parameters.h"
#include "param/env/objects/static/tracers__e2_0o01/group/homogeneous/_member/pair/_a/choice.h"
#include "param/env/objects/static/tracers__e2_0o01/group/homogeneous/_member/pair/_b/choice.h"
namespace c0p {
    using TracersE20O01GroupHomogeneousMemberPairStep = PairSimpleStep<TracersE20O01GroupHomogeneousMemberPairSimpleStepParameters, TracersE20O01GroupHomogeneousMemberPairAStep, TracersE20O01GroupHomogeneousMemberPairBStep>;
}

#endif
