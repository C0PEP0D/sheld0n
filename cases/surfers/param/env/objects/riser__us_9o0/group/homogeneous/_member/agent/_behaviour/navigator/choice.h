#ifndef C0P_PARAM_OBJECTS_RISER__US_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/riser__us_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/riser__us_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/riser__us_9o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename RiserUs9O0GroupHomogeneousMemberAgentActiveStep>
    using RiserUs9O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<RiserUs9O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, RiserUs9O0GroupHomogeneousMemberAgentActiveStep, RiserUs9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<RiserUs9O0GroupHomogeneousMemberAgentActiveStep>, RiserUs9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<RiserUs9O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
