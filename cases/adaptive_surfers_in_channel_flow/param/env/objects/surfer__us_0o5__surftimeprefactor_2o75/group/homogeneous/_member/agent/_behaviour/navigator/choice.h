#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMEPREFACTOR_2O75_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/surfer__us_0o5__surftimeprefactor_2o75/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep, SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs0O5Surftimeprefactor2O75GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
