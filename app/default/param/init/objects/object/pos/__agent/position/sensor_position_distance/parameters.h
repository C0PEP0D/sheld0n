#ifndef C0P_PARAM_INIT_OBJECTS_OBJECT_POS_AGENT_POSITION_SENSOR_POSITION_DISTANCE_PARAMETERS_H
#define C0P_PARAM_INIT_OBJECTS_OBJECT_POS_AGENT_POSITION_SENSOR_POSITION_DISTANCE_PARAMETERS_H
#pragma once

// app include
#include "core/init/objects/object/init/agent/position/sensor_position_distance/prop.h"

#include "param/parameters.h"

namespace c0p {

// Random position initialization at a a specific distance of the sensed position parameters
struct InitObjectPosAgentPositionSensorPositionDistanceParameters {
    const double distance = 1.0 * Parameters::cLength;
};

}

#endif
