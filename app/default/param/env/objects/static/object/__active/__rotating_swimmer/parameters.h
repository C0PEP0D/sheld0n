#ifndef C0P_PARAM_OBJECTS_OBJECT_ACTIVE_ROTATING_SWIMMER_PARAMETERS_H
#define C0P_PARAM_OBJECTS_OBJECT_ACTIVE_ROTATING_SWIMMER_PARAMETERS_H
#pragma once

// core
#include "core/env/objects/object/active/rotating_swimmer/prop.h"

// parameters
#include "param/parameters.h"

namespace c0p {

// Parameters of the step of a swimmer that swims in the direction
// of its local axis that may rotate due to the surrounding flow
struct ObjectActiveRotatingSwimmerStepParameters {
    // Swimming velocity
    TypeScalar velocity = 1.0 * Parameters::cVelocity;
    // Angular swimming velocity
    TypeSpaceVector angularVelocity = TypeSpaceVector::Random().normalized();
};

}

#endif
