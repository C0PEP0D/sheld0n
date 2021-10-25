#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_MATRIX_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_MATRIX_CHOICE_H
#pragma once

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/matrix/jac/core.h"
#include "param/env/objects/object/group/homogeneous/_member/agent/_behaviour/_sensor/matrix/jac/parameters.h"
namespace c0p {
    template<typename ObjectGroupHomogeneousMemberAgentActiveStep>
    using ObjectGroupHomogeneousMemberAgentBehaviourSensorMatrix = AgentBehaviourSensorMatrixJac<ObjectGroupHomogeneousMemberAgentBehaviourSensorMatrixJacParameters, ObjectGroupHomogeneousMemberAgentActiveStep>;
}

#endif
