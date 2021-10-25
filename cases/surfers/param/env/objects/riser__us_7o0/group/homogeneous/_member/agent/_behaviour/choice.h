#ifndef C0P_PARAM_OBJECTS_RISER__US_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/riser__us_7o0/group/homogeneous/_member/agent/_active/choice.h"
// choose your behaviour
#include "param/env/objects/riser__us_7o0/group/homogeneous/_member/agent/_behaviour/navigator/choice.h"
namespace c0p {
    using RiserUs7O0GroupHomogeneousMemberAgentBehaviour = RiserUs7O0GroupHomogeneousMemberAgentBehaviourNavigator<RiserUs7O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
