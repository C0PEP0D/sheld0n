#ifndef C0P_PARAM_OBJECTS_SURFER__US_4O5__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_4O5__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_4o5__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_4o5__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_4o5__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep, SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs4O5Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
