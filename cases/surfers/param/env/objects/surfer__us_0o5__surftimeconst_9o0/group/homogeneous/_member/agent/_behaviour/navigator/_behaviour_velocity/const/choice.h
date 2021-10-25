#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O5__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_0o5__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_0o5__surftimeconst_9o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep, SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>, SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs0O5Surftimeconst9O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
