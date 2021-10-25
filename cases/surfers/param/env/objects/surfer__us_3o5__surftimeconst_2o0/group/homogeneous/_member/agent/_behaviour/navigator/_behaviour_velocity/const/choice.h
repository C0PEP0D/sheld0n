#ifndef C0P_PARAM_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_SURFER__US_3O5__SURFTIMECONST_2O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/surfer__us_3o5__surftimeconst_2o0/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>
    using SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep, SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourSensorDirection<SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>, SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<SurferUs3O5Surftimeconst2O0GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
