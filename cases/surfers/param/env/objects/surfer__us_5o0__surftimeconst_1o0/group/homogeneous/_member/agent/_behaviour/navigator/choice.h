#ifndef C0P_PARAM_OBJECTS_SURFER__US_5O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_5O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_5o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_5o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_5o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep, SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs5O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
