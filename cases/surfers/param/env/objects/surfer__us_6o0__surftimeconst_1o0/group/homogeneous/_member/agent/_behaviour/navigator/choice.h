#ifndef C0P_PARAM_OBJECTS_SURFER__US_6O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_6O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_6o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep, SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs6O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
