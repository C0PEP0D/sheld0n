#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_CHOICE_H
#pragma once

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/core.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/_sensor/direction/accurate/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberAgentActiveStep>
    using ObjectGroupHomogeneousMemberAgentBehaviourSensorDirection = AgentBehaviourSensorDirectionAccurate<ObjectGroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters, ObjectGroupHomogeneousMemberAgentActiveStep>;
}

#endif
