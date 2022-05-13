#ifndef C0P_PARAM_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_8O0__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/static/surfer__vs_8o0__surftimeconst_5o0/group/homogeneous/_member/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/static/surfer__vs_8o0__surftimeconst_5o0/group/homogeneous/_member/agent/_active/swimmer/parameters.h"
#include "core/env/objects/object/active/swimmer/core.h"
namespace c0p {
    using SurferVs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep = ActiveSwimmerStep<SurferVs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters, SurferVs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActivePassiveStep>;
}

#endif