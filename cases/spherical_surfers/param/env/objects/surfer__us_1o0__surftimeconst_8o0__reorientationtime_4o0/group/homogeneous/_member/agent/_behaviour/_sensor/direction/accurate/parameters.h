#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0__REORIENTATIONTIME_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_8O0__REORIENTATIONTIME_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate direction sensor parameters
struct SurferUs1O0Surftimeconst8O0Reorientationtime4O0GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters {
    // Direction sensed
    const TypeSpaceVector direction = {1.0, 0.0, 0.0};
};

}

#endif