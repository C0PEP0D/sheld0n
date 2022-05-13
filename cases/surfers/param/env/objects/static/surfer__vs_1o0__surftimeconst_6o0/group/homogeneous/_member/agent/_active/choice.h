#ifndef C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_6o0/group/homogeneous/_member/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/static/surfer__vs_1o0__surftimeconst_6o0/group/homogeneous/_member/agent/_active/swimmer/parameters.h"
#include "core/env/objects/object/active/swimmer/core.h"
namespace c0p {
    using SurferVs1O0Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep = ActiveSwimmerStep<SurferVs1O0Surftimeconst6O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters, SurferVs1O0Surftimeconst6O0GroupHomogeneousMemberAgentActivePassiveStep>;
}

#endif
