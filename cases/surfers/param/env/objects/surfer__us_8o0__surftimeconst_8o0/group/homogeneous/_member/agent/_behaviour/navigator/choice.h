#ifndef C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMECONST_8O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMECONST_8O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_8o0__surftimeconst_8o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_8o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_8o0__surftimeconst_8o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_8o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_8o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentActiveStep, SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs8O0Surftimeconst8O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
