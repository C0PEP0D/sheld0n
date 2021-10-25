#ifndef C0P_PARAM_OBJECTS_RISER__US_8O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_8O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/core.h"
#include "param/env/objects/riser__us_8o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/accurate/parameters.h"
namespace c0p {
    template<typename RiserUs8O0GroupHomogeneousMemberAgentActiveStep>
    using RiserUs8O0GroupHomogeneousMemberAgentBehaviourSensorDirection = AgentBehaviourSensorDirectionAccurate<RiserUs8O0GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters, RiserUs8O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
