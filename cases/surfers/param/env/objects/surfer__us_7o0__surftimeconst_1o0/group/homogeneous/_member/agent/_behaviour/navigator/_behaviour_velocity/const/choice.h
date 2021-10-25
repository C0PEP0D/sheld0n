#ifndef C0P_PARAM_OBJECTS_SURFER__US_7O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_7O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_7o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_7o0__surftimeconst_1o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep, SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>, SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs7O0Surftimeconst1O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
