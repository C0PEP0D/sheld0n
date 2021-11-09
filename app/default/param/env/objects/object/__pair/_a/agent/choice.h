#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_PAIR_A_AGENT_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

#include "core/env/objects/object/agent/core.h"
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_active/choice.h"
#include "param/env/objects/object/group/homogeneous/_member/pair/_a/agent/_behaviour/choice.h"
namespace c0p {
    using ObjectGroupHomogeneousMemberPairAAgentStep = AgentStep<ObjectGroupHomogeneousMemberPairAAgentActiveStep, ObjectGroupHomogeneousMemberPairAAgentBehaviour>;
}

#endif
