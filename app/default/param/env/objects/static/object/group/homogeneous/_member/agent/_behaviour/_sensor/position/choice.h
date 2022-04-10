#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_CHOICE_H
#pragma once

// THIS FILE SHOULD NOT BE EDITED DIRECTLY BY THE USERS.
// THIS FILE WILL BE AUTOMATICALLY EDITED WHEN THE
// CHOOSE COMMAND IS USED

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/core.h"
#include "param/env/objects/static/object/group/homogeneous/_member/agent/_behaviour/_sensor/position/accurate/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberAgentActiveStep>
    using ObjectGroupHomogeneousMemberAgentBehaviourSensorPosition = AgentBehaviourSensorPositionAccurate<ObjectGroupHomogeneousMemberAgentBehaviourSensorPositionAccurateParameters, ObjectGroupHomogeneousMemberAgentActiveStep>;
}

#endif
