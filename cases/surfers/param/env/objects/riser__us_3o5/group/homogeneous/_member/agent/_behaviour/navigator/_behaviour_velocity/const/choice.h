#ifndef C0P_PARAM_OBJECTS_RISER__US_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/riser__us_3o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/riser__us_3o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/riser__us_3o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename RiserUs3O5GroupHomogeneousMemberAgentActiveStep>
    using RiserUs3O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<RiserUs3O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, RiserUs3O5GroupHomogeneousMemberAgentActiveStep, RiserUs3O5GroupHomogeneousMemberAgentBehaviourSensorDirection<RiserUs3O5GroupHomogeneousMemberAgentActiveStep>, RiserUs3O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<RiserUs3O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
