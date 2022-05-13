#ifndef C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_0O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_0O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/static/surfer__vs_4o0__surftimeconst_0o0/group/homogeneous/_member/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/static/surfer__vs_4o0__surftimeconst_0o0/group/homogeneous/_member/agent/_active/swimmer/parameters.h"
#include "core/env/objects/object/active/swimmer/core.h"
namespace c0p {
    using SurferVs4O0Surftimeconst0O0GroupHomogeneousMemberAgentActiveStep = ActiveSwimmerStep<SurferVs4O0Surftimeconst0O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters, SurferVs4O0Surftimeconst0O0GroupHomogeneousMemberAgentActivePassiveStep>;
}

#endif