#ifndef C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_SURFER__US_2O0__SURFTIMEPREFACTOR_3O0_GROUP_HOMOGENEOUS_MEMBER_AGENT_ACTIVE_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims.
// The swimming direction is not affected by the flow.
struct SurferUs2O0Surftimeprefactor3O0GroupHomogeneousMemberAgentActiveSwimmerStepParameters {
    // Swimming velocity
    TypeSpaceVector velocity = 2.0 * Parameters::cVelocity * TypeSpaceVector::Random().normalized();
};

}

#endif
