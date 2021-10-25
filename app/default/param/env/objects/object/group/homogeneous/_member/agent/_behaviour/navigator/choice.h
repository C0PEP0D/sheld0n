#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/local_axis_swimmer/core.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/navigator/local_axis_swimmer/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberAgentActiveStep>
    using ObjectGroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorLocalAxisSwimmer<ObjectGroupHomogeneousMemberAgentBehaviourNavigatorLocalAxisSwimmerParameters, ObjectGroupHomogeneousMemberAgentActiveStep, ObjectGroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<ObjectGroupHomogeneousMemberAgentActiveStep>, ObjectGroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<ObjectGroupHomogeneousMemberAgentActiveStep>>;
}

#endif
