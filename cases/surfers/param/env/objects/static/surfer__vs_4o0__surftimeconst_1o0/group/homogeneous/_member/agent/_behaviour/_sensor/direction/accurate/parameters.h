#ifndef C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate direction sensor parameters
struct SurferVs4O0Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters {
    // Direction sensed
    const TypeSpaceVector direction = {1.0, 0.0, 0.0};
};

}

#endif
