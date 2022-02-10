#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O1__SURFTIMEPREFACTOR_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_0o1__surftimeprefactor_3o5/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep, SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>, SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>, SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>, SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs0O1Surftimeprefactor3O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
