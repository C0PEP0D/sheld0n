#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_5o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep, SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs0O1Surftimeprefactor5O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif