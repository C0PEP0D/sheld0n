#ifndef C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_1o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentActiveStep, SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs4O0Surftimeprefactor1O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
