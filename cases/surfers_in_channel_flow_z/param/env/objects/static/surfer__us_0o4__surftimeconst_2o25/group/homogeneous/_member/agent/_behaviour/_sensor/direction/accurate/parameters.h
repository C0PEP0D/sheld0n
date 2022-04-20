#ifndef C0P_PARAM_OBJECTS_SURFER__US_0O4__SURFTIMECONST_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_0O4__SURFTIMECONST_2O25_GROUP_HOMOGENEOUS_MEMBER_AGENT_BEHAVIOUR_SENSOR_DIRECTION_ACCURATE_PARAMETERS_H
#pragma once

// app includes
#include "core/env/objects/object/agent/behaviour/sensor/direction/accurate/prop.h"
#include "param/parameters.h"

namespace c0p {

// Accurate direction sensor parameters
struct SurferUs0O4Surftimeconst2O25GroupHomogeneousMemberAgentBehaviourSensorDirectionAccurateParameters {
    // Direction sensed
    const TypeSpaceVector direction = {0.0, 0.0, 1.0};
};

}

#endif
