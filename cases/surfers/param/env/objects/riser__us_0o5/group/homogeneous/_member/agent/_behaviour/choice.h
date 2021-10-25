#ifndef C0P_PARAM_OBJECTS_RISER__US_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/riser__us_0o5/group/homogeneous/_member/agent/_active/choice.h"
// choose your behaviour
#include "param/env/objects/riser__us_0o5/group/homogeneous/_member/agent/_behaviour/navigator/choice.h"
namespace c0p {
    using RiserUs0O5GroupHomogeneousMemberAgentBehaviour = RiserUs0O5GroupHomogeneousMemberAgentBehaviourNavigator<RiserUs0O5GroupHomogeneousMemberAgentActiveStep>;
}

#endif
