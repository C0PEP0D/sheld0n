#ifndef C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__VS_1O0__SURFTIMECONST_6O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate position sensor parameters
struct SurferVs1O0Surftimeconst6O0GroupHomogeneousMemberAgentBehaviourSensorPositionAccurateParameters {
    // Position sensed
    const TypeSpaceVector position = {1.0, 0.0, 0.0};
};

}

#endif
