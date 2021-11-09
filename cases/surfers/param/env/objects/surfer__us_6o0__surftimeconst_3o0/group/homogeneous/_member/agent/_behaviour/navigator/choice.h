#ifndef C0P_PARAM_OBJECTS_SURFER__US_6O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_6O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_6o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_6o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep, SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>, SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>, SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>, SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs6O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
