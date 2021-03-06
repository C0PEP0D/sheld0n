#ifndef C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_0O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMEPREFACTOR_0O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_0o75/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_0o75/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_0o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_0o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_8o0__surftimeprefactor_0o75/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentActiveStep>
    using SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentActiveStep, SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs8O0Surftimeprefactor0O75GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
