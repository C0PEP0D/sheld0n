#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O0__SURFTIMECONST_10O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O0__SURFTIMECONST_10O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_15o0__surftimeconst_10o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_15o0__surftimeconst_10o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep, SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep>, SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs15O0Surftimeconst10O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
