#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/static/surfer__us_0o05__surftimeprefactor_3o0/group/homogeneous/_member/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/static/surfer__us_0o05__surftimeprefactor_3o0/group/homogeneous/_member/agent/_active/swimmer/parameters.h"
#include "core/env/objects/object/active/swimmer/core.h"
namespace c0p {
    using SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentActiveStep = ActiveSwimmerStep<SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters, SurferUs0O05Surftimeprefactor3O0GroupHomogeneousMemberAgentActivePassiveStep>;
}

#endif
