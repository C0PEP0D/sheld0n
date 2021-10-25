#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_CHOICE_H
#pragma once

#include "core/env/objects/object/agent/core.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_active/choice.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/choice.h"
namespace c0p {
    using ObjectGroupHomogeneousMemberAgentStep = AgentStep<ObjectGroupHomogeneousMemberAgentActiveStep, ObjectGroupHomogeneousMemberAgentBehaviour>;
}

#endif
