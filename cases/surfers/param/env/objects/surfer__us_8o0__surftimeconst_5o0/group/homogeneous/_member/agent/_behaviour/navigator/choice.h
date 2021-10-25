#ifndef C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_8O0__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_8o0__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_8o0__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep, SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs8O0Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
