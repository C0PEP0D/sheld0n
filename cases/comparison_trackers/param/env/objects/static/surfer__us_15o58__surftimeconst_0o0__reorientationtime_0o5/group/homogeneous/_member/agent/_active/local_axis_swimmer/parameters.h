#ifndef C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_0O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_15O58__SURFTIMECONST_0O0__REORIENTATIONTIME_0O5_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_LOCAL_AXIS_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/local_axis_swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims in the direction
// of its local axis that may rotate due to the surrounding flow
struct SurferUs15O58Surftimeconst0O0Reorientationtime0O5GroupHomogeneousMemberAgentActiveLocalAxisSwimmerStepParameters {
    // Swimming velocity
    TypeScalar velocity = 15.58 * Parameters::cVelocity;
    // Preferential orientation
    TypeSpaceVector direction = TypeSpaceVector::Random().normalized();
    // Characteristic time to reach the preferential direction in a uniform flow.
    TypeScalar time = 0.5 * Parameters::cTime;
};

}

#endif
