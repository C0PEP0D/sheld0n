#ifndef C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMECONST_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMECONST_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_2o0__surftimeconst_4o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_4o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_2o0__surftimeconst_4o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_4o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_2o0__surftimeconst_4o0/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveStep, SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs2O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
