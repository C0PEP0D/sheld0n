#ifndef C0P_PARAM_OBJECTS_RISER__US_4O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_STRAIGHT_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_4O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_NAVIGATOR_BEHAVIOUR_DIRECTION_STRAIGHT_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// sensor choice
#include "param/env/objects/riser__us_4o5/group/homogeneous/_member/agent/_behaviour/_sensor/direction/choice.h"
// choose your behaviour
#include "core/env/objects/object/agent/behaviour/navigator/behaviour_direction/straight/core.h"
#include "param/env/objects/riser__us_4o5/group/homogeneous/_member/agent/_behaviour/navigator/_behaviour_direction/straight/parameters.h"
namespace c0p {
    template<typename RiserUs4O5GroupHomogeneousMemberAgentActiveStep>
    using RiserUs4O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionStraight = AgentBehaviourNavigatorBehaviourDirectionStraight<RiserUs4O5GroupHomogeneousMemberAgentBehaviourNavigatorBehaviourDirectionStraightParameters, RiserUs4O5GroupHomogeneousMemberAgentActiveStep, RiserUs4O5GroupHomogeneousMemberAgentBehaviourSensorDirection<RiserUs4O5GroupHomogeneousMemberAgentActiveStep>>;
}

#endif
