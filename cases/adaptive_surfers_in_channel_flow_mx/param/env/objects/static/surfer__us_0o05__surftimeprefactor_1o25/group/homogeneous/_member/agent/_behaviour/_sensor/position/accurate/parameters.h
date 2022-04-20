#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_1O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O05__SURFTIMEPREFACTOR_1O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate direction sensor parameters
struct SurferUs0O05Surftimeprefactor1O25GroupHomogeneousMemberAgentBehaviourSensorPositionAccurateParameters {
    // Direction sensed
    const TypeSpaceVector position = TypeSpaceVector::Random() * 2.0 * M_PI;
};

}

#endif
