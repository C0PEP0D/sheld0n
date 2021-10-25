#ifndef C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_6O0__REORIENTATIONTIME_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_1O0__SURFTIMECONST_6O0__REORIENTATIONTIME_3O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/local_axis_swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims in the direction
// of its local axis that may rotate due to the surrounding flow
struct SurferUs1O0Surftimeconst6O0Reorientationtime3O5GroupHomogeneousMemberAgentActiveLocalAxisSwimmerStepParameters {
    // Swimming velocity
    TypeScalar velocity = 1.0 * Parameters::cVelocity; // swim velocity
    // Preferential orientation
    TypeSpaceVector direction = TypeSpaceVector::Random().normalized();
    // Characteristic time to reach the preferential direction in a uniform flow.
    TypeScalar time = 3.5 * Parameters::cTime;
};

}

#endif
