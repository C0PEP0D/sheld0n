#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_BEHAVIOUR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_BEHAVIOUR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "param/env/objects/static/object/group/homogeneous/_member/pair/_a/agent/_active/choice.h"
// choose your behaviour
#include "param/env/objects/static/object/group/homogeneous/_member/pair/_a/agent/_behaviour/navigator/choice.h"
namespace c0p {
    using ObjectGroupHomogeneousMemberPairAAgentBehaviour = ObjectGroupHomogeneousMemberPairAAgentBehaviourNavigator<ObjectGroupHomogeneousMemberPairAAgentActiveStep>;
}

#endif
