#ifndef C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_2o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep, SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs2O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
