#ifndef C0P_PARAM_OBJECTS_SURFER__US_6O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_6O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_6o0__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_6o0__surftimeconst_6o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep, SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>, SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs6O0Surftimeconst6O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
