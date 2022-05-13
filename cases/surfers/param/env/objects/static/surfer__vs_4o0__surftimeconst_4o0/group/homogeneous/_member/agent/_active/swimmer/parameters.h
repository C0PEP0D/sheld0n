#ifndef C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__VS_4O0__SURFTIMECONST_4O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims.
// The swimming direction is not affected by the flow.
struct SurferVs4O0Surftimeconst4O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters {
    // Swimming velocity
    TypeSpaceVector velocity = 4.0 * Parameters::cVelocity * TypeSpaceVector::Random().normalized();
};

}

#endif
