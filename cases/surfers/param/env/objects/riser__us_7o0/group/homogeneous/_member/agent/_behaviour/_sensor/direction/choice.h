#ifndef C0P_PARAM_OBJECTS_RISER__US_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_RISER__US_7O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/core.h"
#include "param/env/objects/riser__us_7o0/group/homogeneous/_member/agent/_behaviour/_sensor/direction/accurate/parameters.h"
namespace c0p {
    template<typename RiserUs7O0GroupHomogeneousMemberAgentActiveStep>
    using RiserUs7O0GroupHomogeneousMemberAgentBehaviourSensorDirection = AgentBehaviourSensorDirectionAccurate<RiserUs7O0GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters, RiserUs7O0GroupHomogeneousMemberAgentActiveStep>;
}

#endif
