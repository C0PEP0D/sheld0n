#ifndef C0P_PARAM_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep, SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>, SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
