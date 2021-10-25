#ifndef C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// behaviour direction choice
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep, SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>, SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs4O0Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
