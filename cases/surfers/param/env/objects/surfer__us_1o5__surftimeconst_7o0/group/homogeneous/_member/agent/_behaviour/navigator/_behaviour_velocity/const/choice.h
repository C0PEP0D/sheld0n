#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O5__SURFTIMECONST_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O5__SURFTIMECONST_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_1o5__surftimeconst_7o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_7o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_1o5__surftimeconst_7o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentActiveStep, SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentActiveStep>, SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs1O5Surftimeconst7O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
