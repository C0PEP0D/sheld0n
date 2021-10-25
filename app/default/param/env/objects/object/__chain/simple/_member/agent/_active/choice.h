#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_CHOICE_H
#pragma once

#include "param/env/objects/object/group/homogeneous/_member/agent/_active/_passive/choice.h"
// choose your object
#include "param/env/objects/object/group/homogeneous/_member/agent/_active/local_axis_swimmer/parameters.h"
#include "core/env/objects/object/active/local_axis_swimmer/core.h"
namespace c0p {
    using ObjectGroupHomogeneousMemberAgentActiveStep = ActiveLocalAxisSwimmerStep<ObjectGroupHomogeneousMemberAgentActiveLocalAxisSwimmerStepParameters, ObjectGroupHomogeneousMemberAgentActivePassiveStep>;
}

#endif
