#ifndef C0P_PARAM_OBJECTS_SURFER__US_3O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_3O0__SURFTIMECONST_9O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims.
// The swimming direction is not affected by the flow.
struct SurferUs3O0Surftimeconst9O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters {
    // Swimming velocity
    TypeSpaceVector velocity = 3.0 * Parameters::cVelocity * TypeSpaceVector::Random().normalized();
};

}

#endif
