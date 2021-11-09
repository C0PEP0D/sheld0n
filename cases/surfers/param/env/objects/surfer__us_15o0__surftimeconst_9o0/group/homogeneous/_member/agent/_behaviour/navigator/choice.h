#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_15o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_15o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep, SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>, SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>, SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>, SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs15O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
