#ifndef C0P_PARAM_OBJECTS_RISER__US_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/riser__us_6o0/group/homogeneous/_member/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/riser__us_6o0/group/homogeneous/_member/agent/_active/swimmer/parameters.h"
#include "core/env/objects/object/active/swimmer/core.h"
namespace c0p {
    using RiserUs6O0GroupHomogeneousMemberAgentActiveStep = ActiveSwimmerStep<RiserUs6O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters, RiserUs6O0GroupHomogeneousMemberAgentActivePassiveStep>;
}

#endif
