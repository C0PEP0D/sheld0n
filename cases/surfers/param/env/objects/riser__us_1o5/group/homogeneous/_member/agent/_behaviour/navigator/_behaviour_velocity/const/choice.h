#ifndef C0P_PARAM_OBJECTS_RISER__US_1O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_1O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_VELOCITY_CONST_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/riser__us_1o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
#include "param/env/objects/riser__us_1o5/group/homogeneous/_member/agent/_behaviour/_sensor/velocity_gradients/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_velocity/const/core.h"
#include "param/env/objects/riser__us_1o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_velocity/const/parameters.h"
namespace c0p {
    template<typename RiserUs1O5GroupHomogeneousMemberAgentActiveStep>
    using RiserUs1O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConst = AgentBehaviourNavigatorBehaviourVelocityConst<RiserUs1O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourVelocityConstParameters, RiserUs1O5GroupHomogeneousMemberAgentActiveStep, RiserUs1O5GroupHomogeneousMemberAgentBehaviourSensorDirection<RiserUs1O5GroupHomogeneousMemberAgentActiveStep>, RiserUs1O5GroupHomogeneousMemberAgentBehaviourSensorVelocityGradients<RiserUs1O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
