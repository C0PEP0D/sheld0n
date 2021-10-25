#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O5__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O5__SURFTIMECONST_5O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_1o5__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_5o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep, SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs1O5Surftimeconst5O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
