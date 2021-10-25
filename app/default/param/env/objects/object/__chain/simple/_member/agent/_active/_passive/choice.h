#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_PASSIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_PASSIVE_CHOICE_H
#pragma once

// choose your object
#include "core/env/objects/object/passive/spheroid/core.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_active/_passive/spheroid/parameters.h"
namespace c0p {
    using ObjectGroupHomogeneousMemberAgentActivePassiveStep = PassiveSpheroidStep<ObjectGroupHomogeneousMemberAgentActivePassiveSpheroidStepParameters>;
}

#endif
