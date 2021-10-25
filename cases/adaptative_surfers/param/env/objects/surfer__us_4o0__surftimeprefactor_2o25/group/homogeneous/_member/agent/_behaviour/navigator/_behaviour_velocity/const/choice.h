#ifndef C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMEPREFACTOR_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_4o0__surftimeprefactor_2o25/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>
    using SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep, SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>, SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs4O0Surftimeprefactor2O25GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
