#ifndef C0P_PARAM_INIT_OBJECTS_SURFER__US_15O58__SURFTIMECONST_2O0__REORIENTATIONTIME_0O5_POS_GROUP_MEMBER_AGENT_POSITION_SENSOR_POSITION_DISTANCE_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_SURFER__US_15O58__SURFTIMECONST_2O0__REORIENTATIONTIME_0O5_POS_GROUP_MEMBER_AGENT_POSITION_SENSOR_POSITION_DISTANCE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/agent/position/sensor_position_distance/prop.h"

#include "param/parameters.h"

namespace c0p {

// Random position initialization at a a specific distance of the sensed position parameters
struct InitSurferUs15O58Surftimeconst2O0Reorientationtime0O5PosGroupMemberAgentPositionSensorPositionDistanceParameters {
    const double distance = 2.0 * M_PI / 3.0;
};

}

#endif
