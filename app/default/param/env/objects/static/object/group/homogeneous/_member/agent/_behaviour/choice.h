#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "param/env/objects/static/object/group/homogeneous/_member/agent/_behaviour/navigator/choice.h"
// choose your active part
#include "param/env/objects/static/object/group/homogeneous/_member/agent/_active/choice.h"
namespace c0p {
    using ObjectGroupHomogeneousMemberAgentBehaviour = ObjectGroupHomogeneousMemberAgentBehaviourNavigator<ObjectGroupHomogeneousMemberAgentActiveStep>;
}

#endif
