#ifndef C0P_PARAM_OBJECTS_OBJECT_ACTIVE_INERTIAL_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_ACTIVE_INERTIAL_SWIMMER_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/active/inertial_swimmer/prop.h"

// parameters
#include "param/parameters.h"

namespace c0p {

// Parameters of the step of an inertial swimmer that swims.
// The swimming direction is not affected by the flow.
struct ObjectActiveInertialSwimmerStepParameters {
    // Terminal swimming velocity
    TypeSpaceVector velocity = 1.0 * Parameters::cVelocity * TypeSpaceVector::Random().normalized();
};

}

#endif
