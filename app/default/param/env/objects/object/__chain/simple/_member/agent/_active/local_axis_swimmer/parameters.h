#ifndef C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/local_axis_swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

struct ObjectGroupHomogeneousMemberAgentActiveLocalAxisSwimmerStepParameters {
    // swimming
    TypeScalar velocity = 1.0 * Parameters::cVelocity; // swim velocity
    // orientation
    TypeSpaceVector direction = TypeSpaceVector::Random().normalized(); // swim direction
    TypeScalar time = 1.0 * Parameters::cTime; // delay time
};

}

#endif
