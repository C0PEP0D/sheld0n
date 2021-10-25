#ifndef C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_4O0__SURFTIMECONST_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_4o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_4o0__surftimeconst_3o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep, SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>, SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs4O0Surftimeconst3O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
