#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O2__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// sub behaviour choice
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/choice.h"
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/swimmer/core.h"
#include "param/env/objects/static/surfer__us_0o2__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/navigator/swimmer/parameters.h"
namespace c0p {
    template<typename SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigator = AgentBehaviourNavigatorSwimmer<SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorSwimmerParameters, SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep, SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>, SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>, SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirection<SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>, SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocity<SurferUs0O2Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
