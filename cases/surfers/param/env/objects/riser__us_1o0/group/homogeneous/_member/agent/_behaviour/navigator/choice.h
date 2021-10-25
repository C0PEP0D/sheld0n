#ifndef C0P_PARAM_OBJECTS_RISER__US_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/riser__us_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/riser__us_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/riser__us_1o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename RiserUs1O0GroupHomogeneousMemberAgentActiveStep>
    using RiserUs1O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<RiserUs1O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, RiserUs1O0GroupHomogeneousMemberAgentActiveStep, RiserUs1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<RiserUs1O0GroupHomogeneousMemberAgentActiveStep>, RiserUs1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<RiserUs1O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
