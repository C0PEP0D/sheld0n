#ifndef C0P_PARAM_OBJECTS_OBJECT_ACTIVE_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_ACTIVE_SWIMMER_PARAMETERS_H
#pragma once

#include "core/env/objects/object/active/swimmer/prop.h"

#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims.
// The swimming direction is not affected by the flow.
struct ObjectActiveSwimmerStepParameters {
    // Swimming velocity
    TypeSpaceVector velocity =  1.0 * Parameters::cVelocity * TypeSpaceVector::Random().normalized();
};

}

#endif
