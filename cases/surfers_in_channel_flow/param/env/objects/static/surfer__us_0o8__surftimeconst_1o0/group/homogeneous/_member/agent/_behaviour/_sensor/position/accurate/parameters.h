#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O8__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O8__SURFTIMECONST_1O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_POSITION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/position/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate direction sensor parameters
struct SurferUs0O8Surftimeconst1O0GroupHomogeneousMemberAgentBehaviourSensorPositionAccurateParameters {
    // Direction sensed
    const TypeSpaceVector position = TypeSpaceVector::Random() * 2.0 * M_PI;
};

}

#endif
