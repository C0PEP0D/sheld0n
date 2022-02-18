#ifndef C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_1O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_2o0__surftimeprefactor_1o5/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentActiveStep>
    using SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentActiveStep, SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentActiveStep>, SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs2O0Surftimeprefactor1O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif