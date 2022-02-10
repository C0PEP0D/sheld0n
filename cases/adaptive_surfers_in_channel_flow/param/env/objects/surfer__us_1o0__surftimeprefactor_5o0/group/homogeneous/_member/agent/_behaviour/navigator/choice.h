#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMEPREFACTOR_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_1o0__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep, SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs1O0Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
