#ifndef C0P_PARAM_OBJECTS_RISER__US_15O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_15O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/riser__us_15o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/riser__us_15o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/riser__us_15o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/riser__us_15o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/riser__us_15o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename RiserUs15O0GroupHomogeneousMemberAgentActiveStep>
    using RiserUs15O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<RiserUs15O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, RiserUs15O0GroupHomogeneousMemberAgentActiveStep, RiserUs15O0GroupHomogeneousMemberAgentBehaviourSensorDirection<RiserUs15O0GroupHomogeneousMemberAgentActiveStep>, RiserUs15O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<RiserUs15O0GroupHomogeneousMemberAgentActiveStep>, RiserUs15O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<RiserUs15O0GroupHomogeneousMemberAgentActiveStep>, RiserUs15O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<RiserUs15O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
