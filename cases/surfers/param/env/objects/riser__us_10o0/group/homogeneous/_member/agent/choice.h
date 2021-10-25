#ifndef C0P_PARAM_OBJECTS_RISER__US_10O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_10O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "core/env/objects/object/agent/core.h"
#include "param/env/objects/riser__us_10o0/group/homogeneous/_member/agent/_active/choice.h"
#include "param/env/objects/riser__us_10o0/group/homogeneous/_member/agent/_behaviour/choice.h"
namespace c0p {
    using RiserUs10O0GroupHomogeneousMemberAgentStep = AgentStep<RiserUs10O0GroupHomogeneousMemberAgentActiveStep, RiserUs10O0GroupHomogeneousMemberAgentBehaviour>;
}

#endif
