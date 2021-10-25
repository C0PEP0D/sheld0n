#ifndef C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SENSOR_MATRIX_CHOICE_H
#define C0P_PARAM_OBJECTS_OBJECT_PAIR_A_AGENT_BEHAVIOUR_SENSOR_MATRIX_CHOICE_H
#pragma once

// choose your behaviour
#include "core/env/objects/object/agent/behaviour/sensor/matrix/jac/core.h"
#include "param/env/objects/object/pair/_a/agent/_behaviour/_sensor/matrix/jac/parameters.h"
namespace c0p {
    template<typename ObjectPairAAgentActiveStep>
    using ObjectPairAAgentBehaviourSensorMatrix = AgentBehaviourSensorMatrixJac<ObjectPairAAgentBehaviourSensorMatrixJacParameters, ObjectPairAAgentActiveStep>;
}

#endif
