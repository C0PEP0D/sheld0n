#ifndef C0P_PARAM_OBJECTS_SURFER__US_10O0__SURFTIMECONST_10O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_10O0__SURFTIMECONST_10O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_10o0__surftimeconst_10o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_10o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_10o0__surftimeconst_10o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep, SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep>, SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs10O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
